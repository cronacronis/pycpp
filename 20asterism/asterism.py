# -*- coding: utf-8 -*-
a = [u'山羊座', u'水瓶座', u'魚座', u'牡羊座', u'牡牛座', u'双子座', u'蟹座', u'獅子座', u'乙女座', u'天秤座', u'蠍座', u'射手座']
b = [20, 19, 20, 20, 20, 21, 23, 23, 23, 23, 22, 22]
m = int(raw_input('月を入力してください: '))
d = int(raw_input('日を入力してください: '))

print(a[ m-13 + (1 if d > b[m-1] else 0) ])
