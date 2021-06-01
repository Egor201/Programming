import telebot
from telebot import types
import requests
import json

bot = telebot.TeleBot('1862801414:AAFR3egoBV7Hu6EOijhanA-OLCqa1hqUan8')
name = '';
@bot.message_handler(commands = ['start'])
def start(message):
    if message.text == '/start':
        bot.send_message(message.from_user.id, "Привет, этот бот создан для помощи молодым предпринимателям. Вы сможете вести учет дохода и расхода за месяц. Бот сможет показать вам краткую статистику и дать рекомендацию. ");
        bot.send_message(message.from_user.id, "Скажите ваше имя");
        bot.register_next_step_handler(message, get_name);
def get_name(message):
    global name;
    keyboard = types.InlineKeyboardMarkup(); 
    key_add = types.InlineKeyboardButton(text='Добавить закупку, наценку и план', callback_data='add');
    keyboard.add(key_add);
    name = message.text;
    bot.send_message(message.from_user.id, 'Хорошо, ' + name + ', теперь вы можете добавлять и удалять любые статьи расходов.');     
    bot.send_message(message.from_user.id, text= 'Для более качественной работы бота, запишите три обязательные статьи: Закупка (закупка расходников), Наценка (наценка на продажу этих расходников в процентах) и  месячный план чистой прибыли', reply_markup = keyboard)

def Send (message, js):
    try:
        res = requests.get('http://localhost:1234/')
    except:
        bot.send_message(message.chat.id, "Извените, возникли какие-то проблемы. Попробуйте написать позже")   
    else:
        if (js["NameArcticl"] == "Закупка" or js["NameArcticl"] == "закупка"):
            js["NameArcticl"] = "Z";
        elif js["NameArcticl"] == "Наценка" or js["NameArcticl"] == "наценка":
            js["NameArcticl"] = "N";
        elif js["NameArcticl"] == "План" or js["NameArcticl"] == "план":
            js["NameArcticl"] = "P";
        url = 'http://localhost:1234/tt'
        resp = requests.post(url,json.dumps(js))
        resp.encoding = 'UTF-8'
        
        q = int(js["ActionCode"])
        if (js["ActionCode"] == 1):
            if (resp.status_code == 200):
                if (resp.text == 'ok'):
                    bot.send_message(message.chat.id, 'Отлично, вы добавили запись');
                    print ("success")
                else:
                    bot.send_message(message.chat.id, "Извените, возникли какие-то проблемы. Сохранить запись не удалось(")
                    print ("error")
            else:
                print (resp.status_code)
        elif (js["ActionCode"] == 2):
            qwe = 0
            if (resp.status_code == 200):
                js = resp.json();
                
                for w in js:
                    if (w["NameArcticl"] == "Z"):
                        w["NameArcticl"] = "Закупка";
                        q = w["Price"]
                        qwe += 1
                    if (w["NameArcticl"] == "N"):
                        w["NameArcticl"] = "Наценка";
                        qw = w["Price"]
                        qwe += 1
                    if (w["NameArcticl"] == "P"):
                        w["NameArcticl"] = "План";
                        qw = w["Price"]
                        qwe += 1
                    # if not(w["NameArcticl"] == " ") and w["Action"]:
                        # bot.send_message(message.chat.id, w["NameArcticl"] + " : " + str(w["Price"]))
                if (qwe == 3):
                    bot.send_message(message.chat.id, "Доход" + " : "+ str(q * (1 + qw / 100)))
                for w in js:
                    if (w["NameArcticl"] == "Наценка"):
                        bot.send_message(message.chat.id, w["NameArcticl"] + " : " + str(w["Price"]) + "%")
                bot.send_message(message.chat.id, "Дополнительные доходы")
                for w in js:
                    if not (w["NameArcticl"] == "Наценка") and not (w["NameArcticl"] == "План"):
                        if not(w["NameArcticl"] == " ") and w["Action"]:
                            bot.send_message(message.chat.id, w["NameArcticl"] + " : " + str(w["Price"]))
                bot.send_message(message.chat.id, "Расходы")
                for w in js:
                    if not(w["NameArcticl"] == " ") and not w["Action"]:
                        bot.send_message(message.chat.id, w["NameArcticl"] + " : " + str(w["Price"]))
                bot.send_message(message.chat.id, "Введите название статьи, которую хотите удалить:")
                bot.register_next_step_handler(message, dele, js);
            else: 
                bot.send_message(message.chat.id, "Извените, возникли какие-то проблемы. Не получается запросить список ваших записей(")
         
        elif (js["ActionCode"] == 3):
            if (resp.status_code == 200):
                if (resp.text == 'ok'):
                    print ("success")
                    bot.send_message(message.chat.id, "Хорошо, все ваши предыдущии записи удаленны. Напишите /start, чтобы начать новую работу с мной")
                else:
                    print ("error")
            else:
                print (resp.status_code)
        elif (js["ActionCode"] == 4):
            if (resp.status_code == 200):
                if (resp.text == "oy"):
                    bot.send_message (message.chat.id, "Вы не добавили что-то из основных статей (Закупка, Наценка или П). С помощью команды /sayAll вы сможете посмотреть все добавленные статьи, а с помощью команды /add добавить недостающие")
                else:
                    js = resp.json();
                    bot.send_message(message.chat.id, "Общий доход : " + str(round(js["income"], 2)) + "; \n" + "Общий расход : " + str(round(js["expense"], 2)) + "; \n"  + "Выручка : " + str(round(js["revenue"], 2)) + "; \n" + "Чистая прибыль : " + str(round(js["netProfit"], 2)) + "; \n")
                    bot.send_message(message.chat.id, "Рентабельность : " + str(round(js["profitability"], 2)))
                    bot.send_message(message.chat.id, "Рекоминдация от бота : " + str(js["Recomendation"]))
            else:
                bot.send_message(message.chat.id, "Извените, возникли какие-то проблемы. Не получается запросить статистику по вам")
                print (resp.status_code)
        elif (js["ActionCode"] == 5):
            if (resp.status_code == 200):
                qwe = 0
                js = resp.json();
                for w in js:
                    if (w["NameArcticl"] == "Z"):
                        w["NameArcticl"] = "Закупка";
                        q = w["Price"]
                        qwe = qwe + 1
                    if (w["NameArcticl"] == "N"):
                        w["NameArcticl"] = "Наценка";
                        qw = w["Price"]
                        qwe = qwe + 1
                if not (qwe == 2):
                    bot.send_message(message.chat.id, "Не получается посчитать основной доход из-за того, что вы не добавили что-то из основных статей (Закупка, Наценка или План).C помощью команды /add вы сможете добавить недостающие")
                else:
                    bot.send_message(message.chat.id, "Доход" + " : "+ str(q * (1 + qw / 100)))
                for w in js:
                    if (w["NameArcticl"] == "Наценка"):
                        bot.send_message(message.chat.id, w["NameArcticl"] + " : " + str(w["Price"]) + "%")
                bot.send_message(message.chat.id, "Дополнительные доходы")
                for w in js:
                    if not (w["NameArcticl"] == "Наценка") and not (w["NameArcticl"] == "План"):
                        if not(w["NameArcticl"] == " ") and w["Action"]:
                            bot.send_message(message.chat.id, w["NameArcticl"] + " : " + str(w["Price"]))
                bot.send_message(message.chat.id, "Расходы")
                for w in js:
                    if not(w["NameArcticl"] == " ") and not w["Action"]:
                        bot.send_message(message.chat.id, w["NameArcticl"] + " : " + str(w["Price"]))
            else: 
                bot.send_message(message.chat.id, "Извените, возникли какие-то проблемы. Не получается запросить список ваших записей(")
                
        elif (js["ActionCode"] == 6):
            if (resp.status_code == 200):
                js = resp.json()
                for w in js:
                    if (w["NameArcticl"] == "Z"):
                        w["NameArcticl"] = "Закупка";
                    if not(w["NameArcticl"] == " "):
                        bot.send_message(message.chat.id, w["NameArcticl"] + " : " + str(round(w["PriceInterest"], 2)) + "%")
                #print (js)
            else:
                print (resp.status_code)
        elif (js["ActionCode"] == 21):
            if (resp.status_code == 200):
                if (resp.text == 'ok'):
                    bot.send_message(message.chat.id, 'Отлично, вы удалили запись');
                    print ("success")
                else:
                    print ("error")
            else:
                bot.send_message(message.chat.id, "Извените, возникли какие-то проблемы. Не получается запросить статистику по вам")
                print (resp.status_code)
    
def write_article(message, check, js, first = False):
    try:
        s = int(message.text);
    except ValueError:
        if not check:
            js["NameArcticl"] = message.text;
            js["ActionCode"] = 1;
            check+=1
            if js["NameArcticl"] == "Наценка":
                bot.send_message(message.chat.id, 'Скажите процент наценки'); 
            else:
                bot.send_message(message.chat.id, 'Скажите сумму в рублях'); 
        else:
            bot.send_message(message.chat.id, 'Это не число, попробуйте еще раз');
            if js["NameArcticl"] == "Наценка":
                bot.send_message(message.chat.id, 'Скажите процент наценки');
            else:
                bot.send_message(message.chat.id, 'Скажите сумму в рублях'); 
        if first:
            bot.register_next_step_handler(message, write_article, check, js, first);
        else:
            bot.register_next_step_handler(message, write_article, check, js);
    else:       
        js["Price"] = s;
        cheating = False
        plan = False
        
        if js["NameArcticl"] == "Закупка":
            cheating = True
        if js["NameArcticl"] == "Наценка":
            plan = True
        Send(message, js)
        
        if first:
            if plan :
                with open('C:/Users/Admin/Desktop/Programming/coursework/texx.json') as file:
                    text = file.read()
                text = json.loads(text)
                check = 1
                text["UserName"] = name;
                text["UserId"] = message.from_user.id;
                text["NameArcticl"] = "План";
                text["Action"] = True
                text["ActionCode"] = 1;
                bot.send_message(message.chat.id, 'Введите месячный План'); 
                bot.register_next_step_handler(message, write_article, check, text, first);
            else:
                if cheating:
                    with open('C:/Users/Admin/Desktop/Programming/coursework/texx.json') as file:
                        text = file.read()
                    text = json.loads(text)
                    check = 1
                    text["UserName"] = name;
                    text["UserId"] = message.from_user.id;
                    text["NameArcticl"] = "Наценка";
                    text["Action"] = True
                    text["ActionCode"] = 1;
                    bot.send_message(message.chat.id, 'Какую вы хотите сделать наценку на закупленный товар? (в процентах)'); 
                    bot.register_next_step_handler(message, write_article, check, text, first);
                else:
                    keyboard = types.ReplyKeyboardMarkup(resize_keyboard=True)
                    buttons = ["Добавить", "Удалить", "Сказать все"]
                    keyboard.add(*buttons)
                    buttons = ["Отчет",  "Статистика расходов", "Новая работа"]
                    keyboard.add(*buttons)
                    bot.send_message(message.chat.id, 'Теперь давайте я вам расскажу про дальнейшуу работу со мной)', reply_markup=keyboard); 
                    bot.send_message(message.chat.id, 'Это набор команд, которыми вы можете пользоваться (также для удобства эти команды продублированны на клавиатуре снизу) : /add команда для записи статьи; /del команда для удаления какой-то статьи; /newWork команда, для того чтобы начать новую работу со мной; /report команда для вывода краткой статистики по введенным статьям; /sayAll команда для вывода всех статей, которые уже записанны; /dopStatistics команда для вывода статистики расходов')
            
            

def dele (message, js):
     for w in js:
        if (w["NameArcticl"] == message.text):
            w["ActionCode"] = 21
            Send(message, w)
            break
 

@bot.message_handler(commands = ['add'])
def add_article (message):
    markup = types.InlineKeyboardMarkup(row_width = 2); 
    income = types.InlineKeyboardButton(text='Доход', callback_data='income');
    expenditure = types.InlineKeyboardButton(text='Расход', callback_data='expenditure');
    markup.add(income, expenditure);
    bot.send_message(message.chat.id, 'Отлично. Выбирайте, что ходите добавить?', reply_markup = markup);
        
@bot.message_handler(commands = ['del'])
def del_article (message):    
    bot.send_message(message.chat.id, 'Вот списот всех статей, которые вы добавляли, в виде Название статьи : сумма.');
    with open('C:/Users/Admin/Desktop/Programming/coursework/texx.json') as file:
        text = file.read()
    text = json.loads(text)
    text["UserId"] = message.from_user.id;
    text["ActionCode"] = 2
    Send(message, text)
        
@bot.message_handler(commands = ['newWork'])
def new_work (message):
    bot.send_message(message.chat.id, 'Данная команда нужну в том случае, если вы хотите полностью стереть все имеющиеся статьи и начать новую работу с ботом');
    markup = types.InlineKeyboardMarkup(row_width = 2); 
    key_y = types.InlineKeyboardButton(text='Да', callback_data='key_y');
    key_n = types.InlineKeyboardButton(text='Нет', callback_data='key_n');
    markup.add(key_y, key_n);
    bot.send_message(message.chat.id, 'Вы уверенны, что хотите удалить все ваши записи?', reply_markup = markup);
    


@bot.message_handler(commands = ['report'])
def statistics(message):
    bot.send_message(message.chat.id, 'Данная команда нужну для вывода отчета по уже записанным статьям');
    with open('C:/Users/Admin/Desktop/Programming/coursework/texx.json') as file:
        text = file.read()
    text = json.loads(text)
    text["UserId"] = message.from_user.id;
    text["ActionCode"] = 4
    Send(message, text)

@bot.message_handler(commands = ['sayAll'])
def sayAll(message):
    bot.send_message(message.chat.id, 'Данная команда нужну для вывода всех статей');
    with open('C:/Users/Admin/Desktop/Programming/coursework/texx.json') as file:
        text = file.read()
    text = json.loads(text)
    text["UserId"] = message.from_user.id;
    text["ActionCode"] = 5
    Send(message, text)

@bot.message_handler(commands = ['dopStatistics'])
def statistics(message):
    bot.send_message(message.chat.id, 'Данная команда нужну для вывода краткой статистики по вашим расходам');
    with open('C:/Users/Admin/Desktop/Programming/coursework/texx.json') as file:
        text = file.read()
    text = json.loads(text)
    text["UserId"] = message.from_user.id;
    text["ActionCode"] = 6
    Send(message, text)
@bot.message_handler(content_types = ['text'])
def button (message):
    if (message.text == 'Добавить'):
        markup = types.InlineKeyboardMarkup(row_width = 2); 
        income = types.InlineKeyboardButton(text='Доход', callback_data='income');
        expenditure = types.InlineKeyboardButton(text='Расход', callback_data='expenditure');
        markup.add(income, expenditure);
        bot.send_message(message.chat.id, 'Отлично. Выбирайте, что ходите добавить?', reply_markup = markup);
    elif message.text == 'Удалить':
        bot.send_message(message.chat.id, 'Вот списот всех статей, которые вы добавляли, в виде Название статьи : сумма.');
        with open('C:/Users/Admin/Desktop/Programming/coursework/texx.json') as file:
            text = file.read()
        text = json.loads(text)
        text["UserId"] = message.from_user.id;
        text["ActionCode"] = 2
        Send(message, text)
    elif message.text == 'Сказать все':
        bot.send_message(message.chat.id, 'Данная команда нужну для вывода всех статей');
        with open('C:/Users/Admin/Desktop/Programming/coursework/texx.json') as file:
            text = file.read()
        text = json.loads(text)
        text["UserId"] = message.from_user.id;
        text["ActionCode"] = 5
        Send(message, text)
    elif message.text == 'Отчет':
        bot.send_message(message.chat.id, 'Данная команда нужну для вывода краткой статистики по уже записанным статьям');
        with open('C:/Users/Admin/Desktop/Programming/coursework/texx.json') as file:
            text = file.read()
        text = json.loads(text)
        text["UserId"] = message.from_user.id;
        text["ActionCode"] = 4
        Send(message, text)
    elif message.text == 'Новая работа':
        bot.send_message(message.chat.id, 'Данная команда нужну в том случае, если вы хотите полностью стереть все имеющиеся статьи и начать новую работу с ботом');
        markup = types.InlineKeyboardMarkup(row_width = 2); 
        key_y = types.InlineKeyboardButton(text='Да', callback_data='key_y');
        key_n = types.InlineKeyboardButton(text='Нет', callback_data='key_n');
        markup.add(key_y, key_n);
        bot.send_message(message.chat.id, 'Вы уверенны, что хотите удалить все ваши записи?', reply_markup = markup);
    elif message.text == 'Статистика расходов':
        bot.send_message(message.chat.id, 'Данная команда нужну для вывода краткой статистики по вашим расходам');
        with open('C:/Users/Admin/Desktop/Programming/coursework/texx.json') as file:
            text = file.read()
        text = json.loads(text)
        text["UserId"] = message.from_user.id;
        text["ActionCode"] = 6
        Send(message, text)
    

@bot.callback_query_handler(func=lambda call: True)
def callback(call):
    if call.data == 'add':
        with open('C:/Users/Admin/Desktop/Programming/coursework/texx.json') as file:
            text = file.read()
        text = json.loads(text)
        text["UserName"] = name;
        text["UserId"] = call.from_user.id;
        text["Action"] = False
        text["NameArcticl"] = "Закупка";
        text["ActionCode"] = 1;
        check = 1
        first = True
        bot.send_message(call.message.chat.id, 'Введите сумму, на которую вы закупились'); 
        bot.register_next_step_handler(call.message, write_article, check, text, first); 
    if call.data == 'income':
        with open('C:/Users/Admin/Desktop/Programming/coursework/texx.json') as file:
            text = file.read()
        text = json.loads(text)
        text["UserName"] = name;
        text["UserId"] = call.from_user.id;
        text["Action"] = True
        check = 0
        bot.send_message(call.message.chat.id, 'Скажите название статьи доходов')
        bot.register_next_step_handler(call.message, write_article, check, text); 
    if call.data == 'expenditure':
        with open('C:/Users/Admin/Desktop/Programming/coursework/texx.json') as file:
            text = file.read()
        text = json.loads(text)
        text["UserName"] = name;
        text["UserId"] = call.from_user.id;
        text["Action"] = False
        check = 0
        bot.send_message(call.message.chat.id, 'Скажите название статьи расходов')
        bot.register_next_step_handler(call.message, write_article, check, text); 
    if call.data == 'key_y':
        with open('C:/Users/Admin/Desktop/Programming/coursework/texx.json') as file:
            text = file.read()
        text = json.loads(text)
        text["UserId"] = call.from_user.id;
        text["ActionCode"] = 3
        Send(call.message, text)
    if call.data == 'key_n':
        bot.send_message(call.message.chat.id, 'Хорошо, команда отменена')
        
    
bot.polling(none_stop = True);