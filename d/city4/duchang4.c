/*  <SecCrypt CPL V3R05>  */
 
//  Room:  /d/changan/duchang4
//  by  snowcat  7/5/1997
inherit  ROOM;

int  room_status  =  0;
object  cs_gui  =  0;
object  qn_gui  =  0;
object  bl_gui  =  0;
int  *res  =  allocate(3);

mapping  guis  =  ([  
    "cs"    :  "���ٹ�",
    "qn"    :  "ǧ���",
    "bl"    :  "���Ϲ�",
  ]);  

int  random2  (int  i)
{
    return  (random(i)+uptime())  %  i;
}

void  create()
{
    set  ("short",  "���귿");
    set  ("long",  @LONG
һ����ɫ���ο�̴�㿿���������������ܷ���һȦ�����ž۾�
����Ŀ��ˡ��м���һ��ʯ�����������һ����������̴��̨��
һλ�������ݵĹ�ͯ��Χ�Ź�̨ת��תȥ���귿�����ǽ�Ϲ�����
��(paizi)�� 
LONG);

    set("item_desc",([
        "paizi"  :  "Ѻ���ٹ꣺  sai cs <amount> <money>\n"+  
                    "Ѻǧ��꣺  sai qn <amount> <money>\n"+  
                    "Ѻ���Ϲ꣺  sai bl <amount> <money>\n",  
    ]));  
    set("objects",  ([  /*  sizeof()  ==  1  */
        __DIR__"npc/guitong"  :  1,
    ]));
    set("exits",  ([  /*  sizeof()  ==  1  */
        "north"  :  __DIR__"clubup",
    ]));
    set("light_up",  1);
    set("no_fight",  1);
    set("no_magic",  1);
    setup();
}

void  init  ()
{
    add_action  ("do_sai","sai");
    add_action  ("do_bian","bian");
    add_action  ("do_fight","fight");
    add_action  ("do_steal","steal");
    add_action  ("do_kill","kill");
    add_action  ("do_cast","cast");
    add_action  ("do_exert","exert");
    add_action  ("do_perform","perform");

    if  (room_status  >  0)
        return;

    remove_call_out  ("gamble_prepare");
    remove_call_out  ("gamble_start");
    remove_call_out  ("gamble_perform");
    remove_call_out  ("gamble_finish");
    call_out  ("gamble_prepare",2);
    room_status  =  1;
}

int  do_sai  (string  arg)
{
    object  me  =  this_player();
    string  what;
    int  amount;
    string  money;
    object  ob;

    if  (!  arg  ||
            sscanf  (arg,"%s %d %s",what,amount,money)  !=  3)
        return  notify_fail("��ʹ�ã�  sai <Ѻ������> <��Ŀ> <����>\n");

    if  (what  !=  "cs"  &&
            what  !=  "qn"  &&
            what  !=  "bl")
        return  notify_fail("��ҪѺʲô���Ĺꣿ\n");

    ob  =  present  (money+"_money",  me);
    if  (!  ob)
        return  notify_fail("������û�����ֻ��ҡ�\n");
    if  (amount  <  1)
        return  notify_fail("���ѺһЩǮ��\n");
    if  (amount  >  ob->query_amount())
        return  notify_fail("�����ϵ�Ǯ����Ѻ��\n");
    if  (amount * (ob->query("base_value")) > 10000 )
        return  notify_fail("������İ������У��ٱ��������ˡ�\n");

    if  (me->query_temp  ("gamble_gui/amount")  >  0)
        return  notify_fail("���Ѿ�Ѻ���ˡ�\n");

    if  (room_status  >  1)
        return  notify_fail("�������������أ��Ե�Ƭ�̡�\n");

    me->set_temp("gamble_gui/kind",what);
    me->set_temp("gamble_gui/amount",amount);
    me->set_temp("gamble_gui/money",money);
    message_vision  (sprintf("$N�ó�%s%s%s������̴��̨�ϣ�Ѻ%s��\n",
                                                    chinese_number(amount),
                                                    ob->query("base_unit"),
                                                    ob->query("name"),
                                                    guis[what]),
                                    me);
    if  (amount  ==  ob->query_amount())
        destruct  (ob);
    else
        ob->add_amount(-amount);

    return  1;
}

int  valid_leave(object  me,  string  dir)
{
    if  (dir  ==  "north")
    {
        if  (me->query_temp  ("gamble_gui/amount")  >  0)  
            message_vision  ("$N����Ѻ���Ǯ��Ҫ�ˡ�\n",me);
        me->delete_temp("gamble_gui");
    }
    return  ::valid_leave(me,dir);
}

void  gamble_prepare  ()
{
    object  room  =  this_object();
    tell_room  (room,"���ݹ�ͯ����ֻ�������̴��̨�ߡ�\n");
    if  (!  cs_gui)
    {
        cs_gui  =  new(__DIR__+"npc/saigui");
        cs_gui->set("name","���ٹ�");
        cs_gui->move(room);
    }
    if  (!  qn_gui)
    {
        qn_gui  =  new(__DIR__+"npc/saigui");
        qn_gui->set("name","ǧ���");
        qn_gui->move(room);
    }
    if  (!  bl_gui)
    {
        bl_gui  =  new(__DIR__+"npc/saigui");
        bl_gui->set("name","���Ϲ�");
        bl_gui->move(room);
    }
    tell_room  (room,"���ݹ�ͯ˵�����λ������Ѻ��һӮ����\n");
    room_status  =  1;
    call_out  ("gamble_start",20);
}
  
void  gamble_start  ()
{
    object  room  =  this_object();
    tell_room  (room,"���ݹ�ͯ˵����λ����ͣѺ��\n");
    tell_room  (room,"Ȼ������ë������ֻ���������̨�ڡ�\n");
    room_status  =  2;
    res[0]  =  0;
    res[1]  =  0;
    res[2]  =  0;
    call_out  ("gamble_perform",1);
}

void  display_gui  (int  i,  string  name,  object  room)
{
    string  gui1  =  "�ܣ�������    ";
    string  gui2  =  "��ĳĳ�꣩��";
    string  gui3  =  "����������    ";
    string  line1  =  "��";
    string  line2  =  "��";
    string  line3  =  "��";
    int  j;

    gui2  =  "��"+name+"����";
    for  (j  =  0;  j  <  res[i];  j++)
    {
        line1  =  line1  +  "..";
        line2  =  line2  +  "..";
        line3  =  line3  +  "..";
    }
    line1  =  line1  +  gui1;
    line2  =  line2  +  gui2;
    line3  =  line3  +  gui3;
    for  (j  =  res[i];  j  <  30;  j++)
    {
        line1  =  line1  +  "    ";
        line2  =  line2  +  "    ";
        line3  =  line3  +  "    ";
    }
    line1  =  line1  +  "��\n";
    line2  =  line2  +  "��\n";
    line3  =  line3  +  "��\n";
    tell_room  (room,line1);
    tell_room  (room,line2);
    tell_room  (room,line3);
}

int  move_on  (int  r)
{
    r  +=  random2(7);
    if  (r  >  30)
        r  =  30;
    return  r;
}

//  to  reduce  the  probability  of  multiple  arrivals
void  boost_guis  (int  *res)
{
    int  i,  j;
    for  (i  =  0;  i  <  10;  i++)
    {
        reset_eval_cost();
        j  =  random2(3);
        if  (res[j]  >=  28)
        {
            res[j]  =  30;
            break;
        }
    }
}

void  gamble_perform  ()
{
    object  room  =  this_object();
//    object  ji;

    tell_room  (room,"\n\n");
    display_gui  (0,"���ٹ�",room);
    display_gui  (1,"ǧ���",room);
    display_gui  (2,"���Ϲ�",room);

    if  (res[0]<30  &&  res[1]<30  &&  res[2]<30)
    {
        res[0]  =  move_on(res[0]);
        res[1]  =  move_on(res[1]);
        res[2]  =  move_on(res[2]);
        boost_guis  (res);
        remove_call_out  ("gamble_perform");
        call_out  ("gamble_perform",1);
        return;
    }

    call_out  ("gamble_finish",1);
    
}

void  player_wins  (object  who,  int  total)
{
    object  money  =  new  ("/clone/money/"+who->query_temp("gamble_gui/money"));
    int  amount  =  who->query_temp("gamble_gui/amount");
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
    object  money  =  new  ("/clone/money/"+who->query_temp("gamble_gui/money"));
    total  =  who->query_temp("gamble_gui/amount");
    message_vision  (sprintf("���ݹ�ͯ��$N���ڹ�̨�ϵ�%s%s%s���ߡ�\n",
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
    if  (res[0]==30  &&  res[1]==30  &&  res[2]==30)
    {
        total  =  0;
        win  =  "none  of  them";
        tell_room  (room,"���ݹ�ͯ̾��������ͬʤ��Ӯ�ң�\n");
    }
    else  if  ((res[0]==30  &&  res[1]==30)  ||
                      (res[1]==30  &&  res[2]==30)  ||
                      (res[2]==30  &&  res[0]==30))
    {
        total  =  0;
        win  =  "none  of  them";
        tell_room  (room,"���ݹ�ͯ̾��������ͬʤ��Ӯ�ң�\n");
    }
    else  if  (res[0]==30)
    {
        total  =  3;
        win  =  "cs";
        tell_room  (room,"���ݹ�ͯϲ����"+guis[win]+"��ʤ��\n");
    }
    else  if  (res[1]==30)
    {
        total  =  3;
        win  =  "qn";
        tell_room  (room,"���ݹ�ͯϲ����"+guis[win]+"��ʤ��\n");
    }
    else  //if  (res[2]==30)
    {
        total  =  3;
        win  =  "bl";
        tell_room  (room,"���ݹ�ͯϲ����"+guis[win]+"��ʤ��\n");
    }
    i  =  sizeof(list);
    while  (i--)
    {
        if  (!userp(list[i]))
            continue;
        if  (list[i]->query_temp("gamble_gui/kind")  ==  win)
            player_wins(list[i],total);
        else  if  (list[i]->query_temp("gamble_gui/kind"))
            player_loses(list[i],total);
        list[i]->delete_temp("gamble_gui");
    }
    tell_room  (room,"\n");
    call_out  ("gamble_prepare",6+random2(7));
}

int  do_bian  (string  arg)
{
    object  who  =  this_player();
    object  room  =  this_object();
    object  ob;

    if  (!arg)
        return  0;

    ob  =  present(arg,room);
    if  (ob  ==  cs_gui  ||  ob  ==  qn_gui  ||  ob  ==  bl_gui)
    {
        message_vision  ("$N�������м�����Լ���ɹꡣ\n",who);
        message_vision  ("���ݹ�ͯ��$N˵�������ˣ��׻�˵�ú����͹�����\n",who);
        return  1;
    }
    return  0;
}

int  do_fight  (string  arg)
{
    object  who  =  this_player();
    object  room  =  this_object();
    object  ob;

    if  (!arg)
        return  0;

    ob  =  present(arg,room);
    if  (ob  ==  cs_gui  ||  ob  ==  qn_gui  ||  ob  ==  bl_gui)
    {
        message_vision  ("$NҪ�����䡣\n",who);
        message_vision  ("���ݹ�ͯ��$N˵�������ˣ��׻�˵�ú����͹궷��\n",who);
        return  1;
    }
    return  0;
}

int  do_steal  (string  arg)
{
    object  who  =  this_player();
//    object  room  =  this_object();

    message_vision  ("$N��͵�ꡣ\n",who);
    message_vision  ("���ݹ�ͯ��$N˵���������Թ�Ҳ��������\n",who);
    return  1;
}

int  do_kill  (string  arg)
{
    object  who  =  this_player();
    object  room  =  this_object();
    object  ob;

    if  (!arg)
        return  0;

    ob  =  present(arg,room);
    if  (ob  ==  cs_gui  ||  ob  ==  qn_gui  ||  ob  ==  bl_gui)
    {
        message_vision  ("$N��ɱ���ꡣ\n",who);
        message_vision  ("���ݹ�ͯ��$N˵����������Īɱ����\n",who);
        return  1;
    }
    return  0;
}

int  do_cast  (string  arg)
{
    object  who  =  this_player();
//    object  room  =  this_object();

    message_vision  ("$N��ģ���������˼������\n",who);
    message_vision  ("���ݹ�ͯ��$N˵�������ˣ�Ī��Ī���Ī�������١�\n",who);
    return  1;
}

int  do_exert  (string  arg)
{
    object  who  =  this_player();
//    object  room  =  this_object();

    message_vision  ("$N����ʩ����\n",who);
    message_vision  ("���ݹ�ͯ��$N˵���������������������������Ĺ��١�\n",who);
    return  1;
}

int  do_perform  (string  arg)
{
    object  who  =  this_player();
//    object  room  =  this_object();

    message_vision  ("$N����ʩ����\n",who);
    message_vision  ("���ݹ�ͯ��$N˵���������������������������Ĺ��١�\n",who);
    return  1;
}
