# Python script that automatically logs in to the wifi via the captive portal
# Uses selenium to input credentials into browser
# selenium guide - https://selenium-python.readthedocs.io/

from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time
import os

###########################################################

website_link="url_for_captive_portal_site"

username="username" 

password="password"

###########################################################

element_for_username="userId"

element_for_password="password"

###########################################################
driver_path = 'D:/Software/chromedriver.exe'

chrome_options = webdriver.ChromeOptions()
chrome_options.add_argument("--disable-extensions")
chrome_options.add_argument('headless')
chrome_options.add_argument('--hide-scrollbars')
chrome_options.add_argument('--disable-gpu')
chrome_options.add_argument('--no-proxy-server')

driver = webdriver.Chrome(driver_path, options = chrome_options)

driver.get(website_link)
username = driver.find_element_by_name(element_for_username)
username.send_keys(username)		
password  = driver.find_element_by_name(element_for_password)
password.send_keys(password)
password.send_keys(Keys.RETURN)


#completely shuts down the webdriver instances, closes all browser windows and safely ends session
driver.quit()

#use driver.close() in order to just close the tab in focus
