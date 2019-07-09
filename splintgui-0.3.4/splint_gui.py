#!/usr/bin/env python2.5
# -*- coding: utf8 -*-
#########################################################################
#
#  GUI for splint
#  Author:  Christoph Thielecke <ct@crissi99@gmx.de>
#  Date:    17-Nov-08
#  Version: 0.3
#
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the
#  Free Software Foundation, Inc.,
#  59 Temple Place - Suite 330, Boston, MA  02111-1307, USA
#######################################################################

import sys
from PyQt4 import QtGui
from PyQt4 import QtCore
import os.path
import os
import time
import struct
import socket
import tarfile
import subprocess
import re
import locale
import string

import ui_splint_gui


VERSION='0.3.4'
LICENSE = """
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the
Free Software Foundation, Inc.,
59 Temple Place - Suite 330, Boston, MA  02111-1307, USA
"""

feedbacklink='Christoph Thielecke <crissi99@gmx.de>'
homelink='http://crissi.linux-administrator.com/linux/splintgui/index.html'
last_base_dir = ''

class SplintGui(QtGui.QMainWindow, ui_splint_gui.Ui_MainWindow):	
	def __init__(self, parent=None, name=None):
		QtGui.QMainWindow.__init__(self, parent)

		self.setupUi(self)
		
		self.setWindowTitle(self.tr('Splint GUI v')+'%s'%str(VERSION))
		
		self.connect(self.actionQuit,QtCore.SIGNAL('triggered()'),self.quitClicked)
		self.connect(self.actionAbout,QtCore.SIGNAL('triggered()'),self.aboutClicked)
		self.connect(self.actionAboutQt,QtCore.SIGNAL('triggered()'),self.aboutQtClicked)
		self.connect(self.ChoosePushButton,QtCore.SIGNAL('clicked()'),self.selectFiles)
		self.connect(self.pathtosplintPushButton,QtCore.SIGNAL('clicked()'),self.selectpathtosplint)
		self.connect(self.CheckPushButton,QtCore.SIGNAL('clicked()'),self.checkClicked)
		
		self.home_dir = ''
		if os.name.lower() == 'nt':
			self.home_dir = os.environ.get('userprofile')
		if os.name.lower() == 'posix':
			self.home_dir = os.environ.get('HOME')
		if os.name.lower() == 'nt':
			self.pathtosplint = self.home_dir+os.sep+'splint.exe'
		if os.name.lower() == 'posix':
			self.pathtosplint = '/usr/bin/splint'
		self.user_config = { 'last_dir': self.home_dir , 'last_file' : '', 'files' : '' , 'x' : '20', 'y':'20' , 'width' : '800', 'height' : '600', 'pathtosplint' : self.pathtosplint, 'splint_options' : '', 'splintcheckmode' : 'standard', 'includedirs':'', 'defines': ''}
		self.user_settings_file = self.home_dir+os.sep+'.splint_gui.cfg'
		self.load_user_settings()
		self.files = [ ]
		
		fileslist = ''
		flist = [ ]
		try:
			flist = eval(str(self.user_config['files']))
		except Exception,e:
			print 'Exception: %s'%str(e)
		print 'files: %s: type: %s'%( flist, str(type(flist) ))
		for file in flist:
			if fileslist != '':
				fileslist+= ' '
			fileslist+= '"'+str(file)+'"'
		self.FilesLineEdit.setText(fileslist)
		self.FilesLineEdit.setEnabled(False)
		if not self.FilesLineEdit == '':
			for file in self.FilesLineEdit.text().split('" "'):
				self.files.append(file.replace('"',''))
		
		self.last_base_dir = ''
		
		self.pathtosplintLineEdit.setText(self.user_config['pathtosplint'])
		self.includedirsLineEdit.setText(self.user_config['includedirs'])
		self.definesLineEdit.setText(self.user_config['defines'])
		self.setGeometry(int(self.user_config['x']),int(self.user_config['y']),int(self.user_config['width']),int(self.user_config['height']))
		
		self.show()
	
	def quitClicked(self):
		self.save_user_settings()
		sys.exit()
	
	def aboutClicked(self):
		mb = QtGui.QMessageBox()
		#QtGui.QMessageBox.setTextFormat(mb,QtCore.Qt.RichText)
		#mb.information(self,'Info', '%s Version %s\n\nLicense:\n%s\n\n<a href="%s">%s</a>\n<h ref="%s">%s</a>'%('SplintGui',str(VERSION),str(LICENSE),homelink,homelink,feedbacklink,feedbacklink),'OK')
		mb.information(self,self.tr('Info'), '%s '%self.tr('SplintGui')+' '+self.tr('Version')+' %s\n\n'%str(VERSION)+' '+self.tr('License:')+'\n%s\n\n%s\t%s\n%s\t%s'%(str(LICENSE),self.tr('Homepage:'), homelink,self.tr('Feedback:'), feedbacklink),self.tr('OK'))

	def aboutQtClicked(self):
		QtGui.QMessageBox.aboutQt(self)
	
	def selectFiles(self):
		self.FilesLineEdit.clear()
		filenames = QtGui.QFileDialog.getOpenFileNames(self, self.tr("Open File"),self.user_config['last_dir'],self.tr("C/C++ files (*.c *.cpp)"))
		
		if not filenames.isEmpty():
			self.files =  [ ]
			try:
				files = ''
				for file in filenames:
					self.files.append(str(file))
					if files != '':
						files += ' '
					files += '\"'+str(file).replace('/', os.sep)+ '\"'
				print 'files txt: %s'%str(files)
				self.FilesLineEdit.setText(files)
			except Exception,e:
				print 'Exception: %s' %str(e)
				pass
			#self.user_config['last_dir']= os.path.dirname(str(self.files[0]))
			#self.user_config['last_file']= str(self.files[0])
			self.user_config['files']= str(self.files)
		return

	def selectpathtosplint(self):
		self.pathtosplintLineEdit.clear()
		filename = str(QtGui.QFileDialog.getOpenFileName(self, self.tr("Open File"),self.user_config['pathtosplint'],self.tr("* All files")))
		filename = filename.replace('/', os.sep)
		self.user_config['pathtosplint'] = filename
		self.pathtosplint = filename
		
		if self.user_config['pathtosplint'] == '':
			if os.name.lower() == 'nt':
				self.user_config['pathtosplint'] = self.home_dir+os.sep+'splint.exe'
			if os.name.lower() == 'posix':
				self.user_config['pathtosplint'] = '/usr/bin/splint'
		self.pathtosplintLineEdit.setText(self.user_config['pathtosplint'])
		self.save_user_settings()
	
	def load_user_settings(self):
		#if QtCore.QFile(self.user_settings_file).exists():
		try:
			#self.log( self.tr('User settings file found at:')+' '+self.user_settings_file+os.sep)
			print 'User settings file found at:'+' '+self.user_settings_file
			settingsfile = open(self.user_settings_file)
			settingslines = settingsfile.readlines()
			for settingsline in settingslines:
				if settingsline[0] == '#':
					#print 'comment, skipping'
					pass
				else:
					#print 'settingsline: '+settingsline.strip(os.linesep)
					setting_name = settingsline.split('=')[0]
					setting_val = settingsline.replace(setting_name+'=','').strip()
					print 'setting_val: \"%s\"'%str(setting_val)
					if setting_name == 'last_dir':
						self.user_config['last_dir']= setting_val
					if setting_name == 'last_file':
						self.user_config['last_file']= setting_val
					if setting_name == 'files':
						self.user_config['files']= setting_val
					if setting_name == 'x':
						try:
							self.user_config['x']= int(setting_val)
						except:
							pass
					if setting_name == 'y':
						try:
							self.user_config['y']= int(setting_val)
						except:
							pass
					if setting_name == 'width':
						try:
							self.user_config['width']= int(setting_val)
						except:
							pass
					if setting_name == 'height':
						try:
							self.user_config['height']= int(setting_val)
						except:
							pass
					if setting_name == 'pathtosplint':
						self.user_config['pathtosplint']= setting_val
						
						if self.user_config['pathtosplint'] == '':
							if os.name.lower() == 'nt':
								self.user_config['pathtosplint'] = self.home_dir+os.sep+'splint.exe'
							if os.name.lower() == 'posix':
								self.user_config['pathtosplint'] = '/usr/bin/splint'
						self.pathtosplintLineEdit.setText(self.user_config['pathtosplint'])
						
					if setting_name == 'includedirs':
						self.user_config['includedirs'] = setting_val
						self.includedirsLineEdit.setText(self.user_config['includedirs'])
					
					if setting_name == 'defines':
						self.user_config['defines']= setting_val
						self.definesLineEdit.setText(self.user_config['defines'])
					
					if setting_name =='splintcheckmode':
						self.user_config['splintcheckmode'] = setting_val
						
						if self.user_config['splintcheckmode'] == 'weak':
							self.weakModeRadioButton.setChecked(True)
						if self.user_config['splintcheckmode'] == 'standard':
							self.standardModeRadioButton.setChecked(True)
						if self.user_config['splintcheckmode'] == 'checks':
							self.checksModeRadioButton.setChecked(True)
						if self.user_config['splintcheckmode'] == 'strict':
							self.strictModeRadioButton.setChecked(True)
						
					if setting_name == 'splint_options':
							self.user_config['splint_options'] = setting_val
							
							#print self.tr('splint_options:')+' %s'%str(self.user_config['splint_options'])
							if '+posixstrictlib' in self.user_config['splint_options']:
								self.posixstrictlibCheckBox.setChecked(True)
							if '+preproc' in self.user_config['splint_options']:
								self.preprocCheckBox.setChecked(True)
							if '+posixlib' in self.user_config['splint_options']:
								self.posixlibCheckBox.setChecked(True)
							if '+warnposix' in self.user_config['splint_options']:
								self.warnposixCheckBox.setChecked(True)
							if '+retvalint' in self.user_config['splint_options']:
								self.retvalintCheckBox.setChecked(True)
							if '+compdef' in self.user_config['splint_options']:
								self.compdefCheckBox.setChecked(True)
							if '+usedef' in self.user_config['splint_options']:
								self.usedefCheckBox.setChecked(True)
							if '+exportlocal' in self.user_config['splint_options']:
								self.exportlocalCheckBox.setChecked(True)
							if '+unrecog' in self.user_config['splint_options']:
								self.unrecogCheckBox.setChecked(True)
							if '+matchanyintegral' in self.user_config['splint_options']:
								self.matchanyintegralCheckBox.setChecked(True)
							if '+imptype' in self.user_config['splint_options']:
								self.imptypeCheckBox.setChecked(True)
							if '+unixlib' in self.user_config['splint_options']:
								self.unixlibCheckBox.setChecked(True)
							if '+ptrnegate' in self.user_config['splint_options']:
								self.ptrnegateCheckBox.setChecked(True)
							if '+bufferoverflowhigh' in self.user_config['splint_options']:
								self.bufferoverflowhighCheckBox.setChecked(True)
							if '+predboolothers' in self.user_config['splint_options']:
								self.predboolothersCheckBox.setChecked(True)
							if '+varuse' in self.user_config['splint_options']:
								self.varuseCheckBox.setChecked(True)
							if '+type' in self.user_config['splint_options']:
								self.typeCheckBox.setChecked(True)
							if '+mayaliasunique' in self.user_config['splint_options']:
								self.mayaliasuniqueCheckBox.setChecked(True)
							if '+boolops' in self.user_config['splint_options']:
								self.boolopsCheckBox.setChecked(True)
							if '+branchstate' in self.user_config['splint_options']:
								self.branchstateCheckBox.setChecked(True)
							if '+nullpass' in self.user_config['splint_options']:
								self.nullpassCheckBox.setChecked(True)
							if '+nullderef' in self.user_config['splint_options']:
								self.nullderefCheckBox.setChecked(True)
							if '+retvalother' in self.user_config['splint_options']:
								self.retvalotherCheckBox.setChecked(True)
							if '+nullret' in self.user_config['splint_options']:
								self.nullretCheckBox.setChecked(True)
							if '+formattype' in self.user_config['splint_options']:
								self.formattypeCheckBox.setChecked(True)
							if '+onlytrans' in self.user_config['splint_options']:
								self.onlytransCheckBox.setChecked(True)
							if '+mustfreefresh' in self.user_config['splint_options']:
								self.mustfreefreshCheckBox.setChecked(True)
							if '+globs' in self.user_config['splint_options']:
								self.globsCheckBox.setChecked(True)
							if '+isoreserved' in self.user_config['splint_options']:
								self.isoreservedCheckBox.setChecked(True)
							if '+namechecks' in self.user_config['splint_options']:
								self.namechecksCheckBox.setChecked(True)
							if '+isolib' in self.user_config['splint_options']:
								self.isolibCheckBox.setChecked(True)
							if '+exportfcn' in self.user_config['splint_options']:
								self.exportfcnCheckBox.setChecked(True)
							if '+gnuextensions' in self.user_config['splint_options']:
								self.gnuextensionsCheckBox.setChecked(True)
							if '+paramuse' in self.user_config['splint_options']:
								self.paramuseCheckBox.setChecked(True)
							if '+exportheader' in self.user_config['splint_options']:
								self.exportheaderCheckBox.setChecked(True)
							if '+declundef' in self.user_config['splint_options']:
								self.declundefCheckBox.setChecked(True)
							if '+temptrans' in self.user_config['splint_options']:
								self.temptransCheckBox.setChecked(True)
							if '+trytorecover' in self.user_config['splint_options']:
								self.trytorecoverCheckBox.setChecked(True)
							if '+nullassign' in self.user_config['splint_options']:
								self.nullassignCheckBox.setChecked(True)
							if '+formatconst' in self.user_config['splint_options']:
								self.formatconstCheckBox.setChecked(True)
							if '+readonlytrans' in self.user_config['splint_options']:
								self.readonlytransCheckBox.setChecked(True)
							if '+noeffect' in self.user_config['splint_options']:
								self.noeffectCheckBox.setChecked(True)
							if '+globstate' in self.user_config['splint_options']:
								self.globstateCheckBox.setChecked(True)
							if '+compdestroy' in self.user_config['splint_options']:
								self.compdestroyCheckBox.setChecked(True)
								
							
                        print "unixlib isChecked "+unicode(self.unixlibCheckBox.isChecked())
								
								
								
			#self.log( self.tr('loaded user settings:')+' '+str(self.user_config))
			#print 'loaded user settings:'+' '+str(self.user_config)
		except Exception,e:
			#self.log( self.tr('User settings file not found.'))
			print 'User settings file not found.'+ ' '+str(e)
			pass
	
	def save_user_settings(self):
		x = self.x()
		if x < 0:
			x = 0
		y = self.y()
		if y < 0:
			y = 0
		if os.name.lower() == 'nt':
			# stupid hack
			#x += 30
			if y < 30:
				y = 30
		self.user_config['x'] = str(x)
		self.user_config['y'] = str(y)
		self.user_config['width'] = str(self.width())
		self.user_config['height'] = str(self.height())
		if str(self.user_config['pathtosplint']) == '':
			if os.name.lower() == 'nt':
				self.user_config['pathtosplint'] = self.home_dir+os.sep+'splint.exe'
			if os.name.lower() == 'posix':
				self.user_config['pathtosplint'] = '/usr/bin/splint'
		#self.user_config['pathtosplint'] = str(self.user_config['pathtosplint'])
		
		self.files = [ ]
		for f in self.FilesLineEdit.text().split('" "'):
			print 'file: %s'%str(f.replace('"', '').replace(os.linesep, ''))
			self.files.append(str(f).replace('"', '').replace(os.linesep, ''))
		print 'self.files: %s'%(str(self.files))
		self.user_config['files'] = str(self.files)
		
		self.user_config['includedirs'] = str(self.includedirsLineEdit.text())
		self.user_config['defines'] = str(self.definesLineEdit.text())
		
		if self.weakModeRadioButton.isChecked():
			self.user_config['splintcheckmode'] == 'weak'
		if self.standardModeRadioButton.isChecked():
			self.user_config['splintcheckmode'] == 'standard'
		if self.checksModeRadioButton.isChecked():
			self.user_config['splintcheckmode'] == 'checks'
		if self.strictModeRadioButton.isChecked():
			self.user_config['splintcheckmode'] == 'strict'
		
		self.user_config['splint_options'] = ''
		if self.unixlibCheckBox.isChecked():
			self.user_config['splint_options'] += ' +unixlib'
		if self.posixlibCheckBox.isChecked():
			self.user_config['splint_options'] += ' +posixlib'
		if self.posixstrictlibCheckBox.isChecked():
			self.user_config['splint_options'] += ' +posixstrictlib'
		if self.preprocCheckBox.isChecked():
			self.user_config['splint_options'] += ' +preproc'
		if self.warnposixCheckBox.isChecked():
			self.user_config['splint_options'] += ' +warnposix'
		if self.retvalintCheckBox.isChecked():
			self.user_config['splint_options'] += ' +retvalint'
		if self.compdefCheckBox.isChecked():
			self.user_config['splint_options'] += ' +compdef'
		if self.usedefCheckBox.isChecked():
			self.user_config['splint_options'] += ' +usedef'
		if self.exportlocalCheckBox.isChecked():
			self.user_config['splint_options'] += ' +exportlocal'
		if self.unrecogCheckBox.isChecked():
			self.user_config['splint_options'] += ' +unrecog'
		if self.matchanyintegralCheckBox.isChecked():
			self.user_config['splint_options'] += ' +matchanyintegral'
		if self.imptypeCheckBox.isChecked():
			self.user_config['splint_options'] += ' +imptype'
		if self.ptrnegateCheckBox.isChecked():
			self.user_config['splint_options'] += ' +ptrnegate'
		if self.bufferoverflowhighCheckBox.isChecked():
			self.user_config['splint_options'] += ' +bufferoverflowhigh'
		if self.predboolothersCheckBox.isChecked():
			self.user_config['splint_options'] += ' +predboolothers'
		if self.varuseCheckBox.isChecked():
			self.user_config['splint_options'] += ' +varuse'
		if self.typeCheckBox.isChecked():
			self.user_config['splint_options'] += ' +type'
		if self.mayaliasuniqueCheckBox.isChecked():
			self.user_config['splint_options'] += ' +mayaliasunique'
		if self.boolopsCheckBox.isChecked():
			self.user_config['splint_options'] += ' +boolops'
		if self.branchstateCheckBox.isChecked():
			self.user_config['splint_options'] += ' +branchstate'
		if self.nullpassCheckBox.isChecked():
			self.user_config['splint_options'] += ' +nullpass'
		if self.nullderefCheckBox.isChecked():
			self.user_config['splint_options'] += ' +nullderef'
		if self.retvalotherCheckBox.isChecked():
			self.user_config['splint_options'] += ' +retvalother'
		if self.nullretCheckBox.isChecked():
			self.user_config['splint_options'] += ' +nullret'
		if self.formattypeCheckBox.isChecked():
			self.user_config['splint_options'] += ' +formattype'
		if self.onlytransCheckBox.isChecked():
			self.user_config['splint_options'] += ' +onlytrans'
		if self.mustfreefreshCheckBox.isChecked():
			self.user_config['splint_options'] += ' +mustfreefresh'
		if self.globsCheckBox.isChecked():
			self.user_config['splint_options'] += ' +globs'
		if self.namechecksCheckBox.isChecked():
			self.user_config['splint_options'] += ' +namechecks'
		if self.isoreservedCheckBox.isChecked():
			self.user_config['splint_options'] += ' +isoreserved'
		if self.isolibCheckBox.isChecked():
			self.user_config['splint_options'] += ' +isolib'
		if self.exportfcnCheckBox.isChecked():
			self.user_config['splint_options'] += ' +exportfcn'
		if self.gnuextensionsCheckBox.isChecked():
			self.user_config['splint_options'] += ' +gnuextensions'
		if self.paramuseCheckBox.isChecked():
			self.user_config['splint_options'] += ' +paramuse'
		if self.exportheaderCheckBox.isChecked():
			self.user_config['splint_options'] += ' +exportheader'
		if self.declundefCheckBox.isChecked():
			self.user_config['splint_options'] += ' +declundef'
		if self.temptransCheckBox.isChecked():
			self.user_config['splint_options'] += ' +temptrans'
		if self.trytorecoverCheckBox.isChecked():
			self.user_config['splint_options'] += ' +trytorecover'
		if self.nullassignCheckBox.isChecked():
			self.user_config['splint_options'] += ' +nullassign'
		if self.formatconstCheckBox.isChecked():
			self.user_config['splint_options'] += ' +formatconst'
		if self.readonlytransCheckBox.isChecked():
			self.user_config['splint_options'] += ' +readonlytrans'
		if self.noeffectCheckBox.isChecked():
			self.user_config['splint_options'] += ' +noeffect'
		if self.globstateCheckBox.isChecked():
			self.user_config['splint_options'] += ' +globstate'
		if self.compdestroyCheckBox.isChecked():
			self.user_config['splint_options'] += ' +compdestroy'
		
		try:
			config_dir=os.path.dirname(self.user_settings_file)
			if not os.path.exists(config_dir):
				os.mkdir(config_dir)
			#print self.tr('User settings file:')+' '+self.user_settings_file
			settingsfile = open(self.user_settings_file,'w')
			for setting_name in self.user_config.keys():
				settingsfile.write(setting_name+'='+self.user_config[setting_name]+os.linesep)
				#print 'Write setting: %s=%s'%(setting_name,self.user_config[setting_name])
			settingsfile.close()
			#print 'Settings saved.'
		except Exception,e:
			#self.log( self.tr('User settings file could not written to:')+' '+self.user_settings_file)
			print 'User settings file could not written to:'+' '+self.user_settings_file
			#self.log( self.tr('Exception:')+' %s'%str(e))
			print 'Exception:'+' %s'%str(e)
			print str(e)
	
	def checkClicked(self):
		global last_base_dir
		self.OutputTextEdit.clear()
		
		output = ''
		output_error = ''
		input_txt = ''
		cmd =''
		
		if len(self.files) > 0:
			print 'path to splint: %s'%str(self.pathtosplint)
			if not os.path.isfile(str(self.pathtosplint)):
				mb = QtGui.QMessageBox()
				mb.critical(self,self.tr('No splint'), '%s '%str(self.tr('Splint could not found. Please check the path:'))+' '+str(self.pathtosplint))
			else:
			
				self.user_config['splint_options'] = ''
				if self.posixstrictlibCheckBox.isChecked():
					self.user_config['splint_options'] += ' +posixstrictlib'
				if not self.preprocCheckBox.isChecked():
					self.user_config['splint_options'] += ' -preproc'
				if self.posixlibCheckBox.isChecked():
					self.user_config['splint_options'] += ' +posixlib'
				if not self.warnposixCheckBox.isChecked():
					self.user_config['splint_options'] += ' -warnposix'
				if not self.retvalintCheckBox.isChecked():
					self.user_config['splint_options'] += ' -retvalint'
				if not self.compdefCheckBox.isChecked():
					self.user_config['splint_options'] += ' -compdef'
				if not self.usedefCheckBox.isChecked():
					self.user_config['splint_options'] += ' -usedef'
				if not self.exportlocalCheckBox.isChecked():
					self.user_config['splint_options'] += ' -exportlocal'
				if not self.unrecogCheckBox.isChecked():
					self.user_config['splint_options'] += ' -unrecog'
				if self.matchanyintegralCheckBox.isChecked():
					self.user_config['splint_options'] += ' +matchanyintegral'
				if not self.imptypeCheckBox.isChecked():
					self.user_config['splint_options'] += ' -imptype'
				if self.ptrnegateCheckBox.isChecked():
					self.user_config['splint_options'] += ' +ptrnegate'
				if not self.bufferoverflowhighCheckBox.isChecked():
					self.user_config['splint_options'] += ' -bufferoverflowhigh'
				if not self.predboolothersCheckBox.isChecked():
					self.user_config['splint_options'] += ' -predboolothers'
				if not self.varuseCheckBox.isChecked():
					self.user_config['splint_options'] += ' -varuse'
				if not self.typeCheckBox.isChecked():
					self.user_config['splint_options'] += ' -type'
				if not self.mayaliasuniqueCheckBox.isChecked():
					self.user_config['splint_options'] += ' -mayaliasunique'
				if not self.boolopsCheckBox.isChecked():
					self.user_config['splint_options'] += ' -boolops'
				if not self.branchstateCheckBox.isChecked():
					self.user_config['splint_options'] += ' -branchstate'
				if not self.nullpassCheckBox.isChecked():
					self.user_config['splint_options'] += ' -nullpass'
				if not self.nullderefCheckBox.isChecked():
					self.user_config['splint_options'] += ' -nullderef'
				if not self.retvalotherCheckBox.isChecked():
					self.user_config['splint_options'] += ' -retvalother'
				if not self.nullretCheckBox.isChecked():
					self.user_config['splint_options'] += ' -nullret'
				if not self.formattypeCheckBox.isChecked():
					self.user_config['splint_options'] += ' -formattype'
				if not self.onlytransCheckBox.isChecked():
					self.user_config['splint_options'] += ' -onlytrans'
				if not self.mustfreefreshCheckBox.isChecked():
					self.user_config['splint_options'] += ' -mustfreefresh'
				if not self.globsCheckBox.isChecked():
					self.user_config['splint_options'] += ' -globs'
				if not self.isoreservedCheckBox.isChecked():
					self.user_config['splint_options'] += ' -isoreserved'
				if not self.namechecksCheckBox.isChecked():
					self.user_config['splint_options'] += ' -namechecks'
				if not self.isolibCheckBox.isChecked():
					self.user_config['splint_options'] += ' -isolib'
				if not self.exportfcnCheckBox.isChecked():
					self.user_config['splint_options'] += ' -exportfcn'
				if self.gnuextensionsCheckBox.isChecked():
					self.user_config['splint_options'] += ' +gnuextensions'
				if not self.paramuseCheckBox.isChecked():
					self.user_config['splint_options'] += ' -paramuse'
				if not self.exportheaderCheckBox.isChecked():
					self.user_config['splint_options'] += ' -exportheader'
				if not self.declundefCheckBox.isChecked():
					self.user_config['splint_options'] += ' -declundef'
				if not self.temptransCheckBox.isChecked():
					self.user_config['splint_options'] += ' -temptrans'
				if self.trytorecoverCheckBox.isChecked():
					self.user_config['splint_options'] += ' +trytorecover'
				if not self.nullassignCheckBox.isChecked():
					self.user_config['splint_options'] += ' -nullassign'
				if not self.formatconstCheckBox.isChecked():
					self.user_config['splint_options'] += ' -formatconst'
				if not self.readonlytransCheckBox.isChecked():
					self.user_config['splint_options'] += ' -readonlytrans'
				if not self.noeffectCheckBox.isChecked():
					self.user_config['splint_options'] += ' -noeffect'
				if not self.globstateCheckBox.isChecked():
					self.user_config['splint_options'] += ' -globstate'
				if not self.compdestroyCheckBox.isChecked():
					self.user_config['splint_options'] += ' -compdestroy'
					
				
					
				cmdlist = [ ]
				cmd = str(self.user_config['pathtosplint']).replace('/', os.sep)+' '
				
				if self.weakModeRadioButton.isChecked():
					cmd+= '-weak'
				if self.standardModeRadioButton.isChecked():
					cmd+= '-standard'
				if self.checksModeRadioButton.isChecked():
					cmd+= '-checks'
				if self.strictModeRadioButton.isChecked():
					cmd+= '-strict '
				
				options = self.user_config['splint_options'].split(' ')
				linelen= len(cmd)
				for option in options:
					cmd += ' '+str(option)
					cmdlist.append(str(option))
					if linelen > 100:
						cmd += ' \\'+os.linesep
						linelen=0
					else:
						linelen+=len(str(option))+1
				
				cmd += ' \\'+os.linesep
				
				if str(self.definesLineEdit.text()) != '':
					cmdlist.append(str(str(self.definesLineEdit.text())))
					cmd+= ' '+str(self.definesLineEdit.text())+''
					cmd += ' \\'+os.linesep
				if str(self.includedirsLineEdit.text()) != '':
					cmdlist.append(str(str(self.includedirsLineEdit.text())))
					cmd+= ' '+str(self.includedirsLineEdit.text())+''
					cmd += ' \\'+os.linesep
				
				#cmd += ' '+str(self.FilesLineEdit.text().replace(os.sep, '').replace('"', ''))
				#cmdlist.append(str(self.FilesLineEdit.text()).replace(os.sep, '').replace('"', ''))
				
				outputtext = ''
				#outputtext += '<p><b>%s</b><p><pre>%s</pre>' %(self.tr('command:'), str(cmd))
				
				QtGui.QApplication.setOverrideCursor(QtGui.QCursor(QtCore.Qt.WaitCursor))
				self.last_base_dir = ''
				self.files = [ ]
				for f in self.FilesLineEdit.text().split('" "'):
					print 'file: %s'%str(f.replace('"', '').replace(os.linesep, ''))
					self.files.append(str(f).replace('"', '').replace(os.linesep, ''))
				for f in self.files:
					file = ''
					if not os.sep in f:
						basedir = last_base_dir
						#print 'last_dir (1): %s'%str(last_base_dir)
					else:
						basedir = os.path.dirname(str(f))
						if basedir != os.getcwd() and os.path.isdir(basedir):
							#print 'changing to: %s'%str(basedir)
							os.chdir(basedir)
						last_base_dir = basedir
						#print 'last_dir (2): %s'%str(last_base_dir)
						#print 'current_dir: %s'%str(os.getcwd())
						#print 'file1: %s'%f
						#f = f.replace(str(basedir+os.sep), '.'+os.sep)
						file = str(f).replace('/', os.sep)
						file = file.replace(str(basedir+os.sep), '')
						#print 'file: %s'%file
					
					print 'file: %s, basedir: %s'%(str(file), str(basedir))
					cmd2 = cmd
					cmd2 += ' '+str(file)
					
					cmdlist2 = [ ]
					for item in cmdlist:
						cmdlist2.append(item)
					cmdlist2.append(file)
					
					
					outputtext += '<font color="red"><b>%s</b> %s</font>' %(self.tr('processing file:'), str(file))
					outputtext += '<p><b>%s</b> %s'%(self.tr('Running from dir:'), basedir)
					output = ''
					output_error = ''
					#print 'current_dir (3): %s'%str(os.getcwd())
					#print 'last_dir (3): %s'%str(last_base_dir)
					try:
						close_fds = True
						use_shell = False
						cwd = basedir
						executable = str(self.user_config['pathtosplint']).replace('/', os.sep)
						if os.name.lower() == 'nt':
							close_fds = False
							use_shell = False
							executable = str(self.user_config['pathtosplint']).replace('/', os.sep)
							cmd2 = cmd2.replace('/', os.sep)
						
						p = subprocess.Popen(args=cmdlist2, shell=use_shell, cwd=cwd, stdin=subprocess.PIPE, stderr=subprocess.PIPE, stdout=subprocess.PIPE, close_fds=close_fds, executable=executable)
						(child_stdout, child_stderr, child_stdin) = (p.stdout, p.stderr, p.stdin)
						output = child_stdout.readlines()
						output_error = child_stderr.readlines()
						
						child_stdout.close()
						child_stdin.close()
						child_stderr.close()
					except Exception,e:
						print 'Error: %s'%str(e)
						import sys
						import traceback
						(exceptionType, exceptionValue, tb) = sys.exc_info()
						print '%s, %s'%(str(exceptionType),str(exceptionValue))
						for line in traceback.format_tb(tb):
							print '%s'%str(line)
					
					#print 'current_dir (4): %s'%str(os.getcwd())
					#print 'last_dir (4): %s'%str(last_base_dir)
					
					#outputtext += '<p><b>%s</b><p><pre>%s</pre>' %(str(self.tr('command args (cmdlist):')), str(string.join(cmdlist2,' ')))
					outputtext += '<p><b>%s</b><p><pre>%s</pre>' %(self.tr('command:'), str(cmd2))
					outputtext += '<p><b>============= stdout: =============</b></p><font color="darkgreen"><pre>'
					for stdout_line in output:
						if 'redundant with current value' in stdout_line:
							pass
						else:
							outputtext+= stdout_line
					outputtext += '</pre></font>'
					outputtext += '<br /><br />'
					outputtext += '<p><b>============ end stdout =============</b>'
					outputtext += '<p><b>============= stderr: =============</b></p>'
					for stderr_line in output_error:
						if stderr_line.strip() == '':
							continue
						if 'Splint ' in stderr_line:
							pass
						else:
							if 'Finished checking' in stderr_line:
								check_result = 'unknown'
								#print 'stderr_line: %s '%str(stderr_line)
								check_result_raw = str(stderr_line.split('---')[1].strip())
								#print 'check_result_raw: %s '%str(check_result_raw)
								if 'no warnings' in check_result_raw:
									check_result ='<font color="darkgreen"><pre>%s</font>'%(check_result_raw).decode('ascii', 'replace')
								else:
									check_result ='<font color="orange">%s</font>'%str(check_result_raw).decode('ascii', 'replace')
								outputtext += '<p><b>=========== end stderr ==============</b></p>'
								outputtext += '<font color="blue"><pre>%s</pre></font> %s' %('Finished checking:'+' ', str(check_result).decode('ascii', 'replace'))
							else:
								outputtext+= '<font color="red"><pre>%s</pre></font>'%str(stderr_line).decode('ascii', 'replace')
					outputtext += '<p><b>================================</b><br />'
				
				outputtext +='<font color="darkgreen"><pre>%s</font>' %(self.tr('Checking finished'))
				self.OutputTextEdit.setHtml ('%s'%(outputtext))
				QtGui.QApplication.restoreOverrideCursor()
				
				#self.OutputTextEdit.setText ('command:\n%s\n============\nstdout:\n%s\n============\nstderr:\n%s'%(cmd, str(output),str(output_error)))

##### __MAIN__ #####
if __name__=='__main__':
	a = QtGui.QApplication(sys.argv)
	
	try:
		import splint_gui_rc
	except Exception,e:
		#pass
		print 'registerResource: %s'%str(e)
	
	translation_file=''
	language = ''
	try:
		language = locale.getdefaultlocale()[0].split('_')[0].lower()
		print 'locale found: %s'%str(language)
	except:
		pass
	if QtCore.QFile(':/%s.qm'%language).exists():
		translator = QtCore.QTranslator()
		translator.load( ":/%s.qm"%language, "." )
		a.installTranslator( translator )
		translation_lang = QtCore.QObject().tr('FILL YOUR LANGUAGE NAME HERE')
		#print 'translation file for %s found, it will be used.'%translation_lang
	#else:
		#print 'translation file not found.'
	
	w = SplintGui()
	
	w.show()
	sys.exit(a.exec_())

