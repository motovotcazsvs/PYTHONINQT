import requests
from bs4 import BeautifulSoup
import time

timing = time.time()
while True:
    if time.time() - timing > 5.0:
        timing = time.time()
        url = 'https://onlineradiobox.com/ru/radiorecord/'
        response = requests.get(url)
        soup = BeautifulSoup(response.text, 'lxml')
        quotes = soup.find_all('section', class_='station-onair')
        #for quote in quotes:
        #    with open("record_title_music.txt", "w") as record:
        #       record.write(quote.text)
        record = open('record_title_music.txt', 'w')
        for quote in quotes:
            record.write(quote.text)
        record.close()

