/*  <SecCrypt CPL V3R05>  */
 
//  Room:  /d/changan/duchang1
//  by  snowcat  7/5/1997
inherit  ROOM;

int  room_status  =  0;
int  *res  =  allocate(5);

int  random2  (int  i)
{
    return  (random(i)+uptime())  %  i;
}

mapping  qians  =  ([  
    "dqq"  :  "��Ǭǩ",
    "dkq"  :  "����ǩ",
    "xqq"  :  "СǬǩ",
    "xkq"  :  "С��ǩ",
    "qq"    :  "Ǭǩ",
    "kq"    :  "��ǩ",
]);  

void  create()
{
    set  ("short",  "Ѻǩ��");
    set  ("long",  @LONG
һȺ��Χ����̴ľ������������ϯ����һλ���ݵ�ǩ�ͣ�����
һ�������ش����ں���������һ��һ��������Ǭ��ǩ��������
���ϡ�

ǽ����һ��д�ţ�
        ��Ǭǩ��ȫ�������ΪǬǩ����һӮ��ʮ��
        ����ǩ��ȫ�������Ϊ��ǩ����һӮ��ʮ��
        СǬǩ�������ĸ���ΪǬǩ����һӮʮ��
        С��ǩ�������ĸ���Ϊ��ǩ����һӮʮ��
          Ǭǩ������������ΪǬǩ����һӮ��
          ��ǩ������������Ϊ��ǩ����һӮ��

�ҽ���һ������(paizi)��
LONG);

    set("item_desc",([
        "paizi"  :  "Ѻ��Ǭǩ��  qian dqq <amount> <money>\n"+  
                    "Ѻ����ǩ��  qian dkq <amount> <money>\n"+  
                    "ѺСǬǩ��  qian xqq <amount> <money>\n"+  
                    "ѺС��ǩ��  qian xkq <amount> <money>\n"+  
                    "ѺǬǩ��     qian qq <amount> <money>\n"+  
                    "Ѻ��ǩ��     qian kq <amount> <money>\n\n"+
                    "Ϊ���Ʋ���¥  ��Ѻһ���ƽ�\n",
    ]));  
    set("exits",  ([  /*  sizeof()  ==  1  */
        "east"  :  __DIR__"clubup",
    ]));
    set("objects",  ([  /*  sizeof()  ==  1  */
        __DIR__"npc/qianke"  :  1,
    ]));
    set("light_up",  1);
    set("no_fight",  1);
    set("no_beg",  1);
    setup();
}

void  init  ()
{
    add_action  ("do_qian","qian");

    if  (room_status  >  0)
        return;

    remove_call_out  ("gamble_prepare");
    remove_call_out  ("gamble_start");
    remove_call_out  ("gamble_perform");
    remove_call_out  ("gamble_finish");
    call_out  ("gamble_prepare",2);
    room_status  =  1;
}

int  do_qian  (string  arg)
{
    object  me  =  this_player();
    string  what;
    int  amount;
    string  money;
    object  ob;

    if  (!arg  ||
            sscanf(arg,"%s %d %s",what,amount,money)  !=  3)
        return notify_fail("��ʹ�ã�  qian <Ѻǩ����> <��Ŀ> <����>\n");

    if  (what  !=  "dqq"  &&
            what  !=  "dkq"  &&
            what  !=  "xqq"  &&
            what  !=  "xkq"  &&
            what  !=  "qq"  &&
            what  !=  "kq")
        return  notify_fail("��ҪѺʲôǩ��\n");

    ob  =  present  (money+"_money",  me);
    if  (!  ob)
        return  notify_fail("������û�����ֻ��ҡ�\n");
    if  (amount  <  1)
        return  notify_fail("���ѺһЩǮ��\n");
    if  (amount  >  ob->query_amount())
        return  notify_fail("�����ϵ�Ǯ����Ѻ��\n");
    if  (amount * (ob->query("base_value")) > 10000 )
        return  notify_fail("������İ������У��ٱ��������ˡ�\n");

    if  (me->query_temp  ("gamble_qian/amount")  >  0)
        return  notify_fail("���Ѿ�Ѻ���ˡ�\n");

    if  (room_status  >  1)
        return  notify_fail("�������ڶ��أ��Ե�Ƭ�̡�\n");

    me->set_temp("gamble_qian/kind",what);
    me->set_temp("gamble_qian/amount",amount);
    me->set_temp("gamble_qian/money",money);
    message_vision  (sprintf("$N�ó�%s%s%s��Ѻ��%s�ϡ�\n",
                                                    chinese_number(amount),
                                                    ob->query("base_unit"),
                                                    ob->query("name"),
                                                    qians[what]),
                                    me);
    if  (amount  ==  ob->query_amount())
        destruct  (ob);
    else
        ob->add_amount(-amount);

    return  1;
}

int  valid_leave(object  me,  string  dir)
{
    if  (dir  ==  "east")
    {
        if  (me->query_temp  ("gamble_qian/amount")  >  0)  
            message_vision  ("$N����Ѻǩ��Ǯ��\n",me);
        me->delete_temp("gamble_qian");
    }
    return  ::valid_leave(me,dir);
}

void  gamble_prepare  ()
{
    object  room  =  this_object();
    object  *inv;
    int  i;

    tell_room  (room,"ǩ�ͽ�һ����ǩ�����ϻ�������Ѹ��ϴ��һ�顣\n");
    tell_room  (room,"ϴǩ֮��ǩ��ž��һ����ǩװ�����ںУ��е�����Ѻ��\n");
    
    inv=all_inventory();
    i=sizeof(inv);
    while(i--)  {
            if(userp(inv[i]))  {
                  room_status  =  1;
                  call_out  ("gamble_start",25);
	  return;
            }
    }
    room_status=0;
    return;
}
  
void  gamble_start  ()
{
    object  room  =  this_object();
    tell_room  (room,"ǩ�ͺ�����ͣѺ��\n");
    tell_room  (room,"Ȼ������۾��������ںд򿪴��￪ʼ�����ǩ��\n");
    room_status  =  2;
    call_out  ("gamble_perform",3,0);
    call_out  ("gamble_perform",6,1);
    call_out  ("gamble_perform",9,2);
    call_out  ("gamble_perform",12,3);
    call_out  ("gamble_perform",15,4);
    call_out  ("gamble_finish",18);
}

void  gamble_perform  (int  i)
{
    object  room  =  this_object();

    switch  (random2(2))
    {
        case  0:
        {
            tell_room  (room,"\n����    ��    ǩ    ����\n");
            res[i]  =  0;
            break;
        }
        case  1:
        {
            tell_room  (room,"\n����    Ǭ    ǩ    ����\n");
            res[i]  =  1;
            break;
        }
    }
}

void  player_wins  (object  who,  int  total)
{
    object  money  =  new  ("/clone/money/"+who->query_temp("gamble_qian/money"));
    int  amount  =  who->query_temp("gamble_qian/amount");
    total  =  total  *  amount;
    money->set_amount(total);
    message_vision  (sprintf("$NӮ��%s%s%s��\n",
                                                    chinese_number(total),
                                                    money->query("base_unit"),
                                                    money->query("name")),
                                    who);
    money->move(who);
}

void  player_loses  (object  who,  int  total)
{
    object  money  =  new  ("/clone/money/"+who->query_temp("gamble_qian/money"));
    total  =  who->query_temp("gamble_qian/amount");
    message_vision  (sprintf("ǩ�ͽ�$NѺ�����е�%s%s%s���ߡ�\n",
                                                    chinese_number(total),
                                                    money->query("base_unit"),
                                                    money->query("name")),
                                    who);
    destruct  (money);
}

void  gamble_finish  ()
{
    string  win;
    int  total,  i;
    object  room  =  this_object();
    object  *list  =  all_inventory(room);
    if  (res[0]==1  &&  res[1]==1  &&  res[2]==1  &&  res[3]==1  &&  res[4]==1)
    {
        total  =  32;
        win  =  "dqq";
    }
    else  if  (res[0]==0  &&  res[1]==0  &&  res[2]==0  &&  res[3]==0  &&  res[4]==0)
    {
        total  =  32;
        win  =  "dkq";
    }
    else  if  ((res[0]==1  &&  res[1]==1  &&  res[2]==1  &&  res[3]==1)  ||
                      (res[1]==1  &&  res[2]==1  &&  res[3]==1  &&  res[4]==1))
    {
        total  =  16;
        win  =  "xqq";
    }
    else  if  ((res[0]==0  &&  res[1]==0  &&  res[2]==0  &&  res[3]==0)  ||
                      (res[1]==0  &&  res[2]==0  &&  res[3]==0  &&  res[4]==0))
    {
        total  =  16;
        win  =  "xkq";
    }
    else  
    {
        int  r  =  0;
        total  =  2;
        for  (i  =  0;  i  <  5;  i++)
            r  +=  res[i];
        if  (r  >=  3)
            win  =  "qq";
        else
            win  =  "kq";
    }
    tell_room  (room,"\nǩ�������۾���Ѹ�ٿ�һ�����棬�е���"+qians[win]+"��\n");
    i  =  sizeof(list);
    while  (i--)
    {
        if  (!userp(list[i]))
            continue;
        if  (list[i]->query_temp("gamble_qian/kind")  ==  win)
            player_wins(list[i],total);
        else  if  (list[i]->query_temp("gamble_qian/kind"))
            player_loses(list[i],total);
        list[i]->delete_temp("gamble_qian");
    }
    tell_room  (room,"\n");
    call_out  ("gamble_prepare",5);
}
