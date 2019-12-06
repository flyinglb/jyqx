/*  <SecCrypt CPL V3R05>  */
 
//  Room:  /d/changan/duchang3
//  by  snowcat  7/5/1997
inherit  ROOM;

int  room_status  =  0;
object  hg_ji  =  0;
object  lw_ji  =  0;

mapping  jis  =  ([  
    "hg"    :  "��ڼ�",
    "lw"    :  "��β��",
  ]);  

int  random2  (int  i)
{
    return  (random(i)+uptime())  %  i;
}

void  create()
{
    set  ("short",  "������");
    set  ("long",  @LONG 
��������һ��һ�ҷ���������������һ�����������һȺ��
�ڼ�����һ�����������һȺ��β���������������߳߼����Ķ���
������һȦ�͵͵���������Χ�ɡ�һλ���׼������������Ŷ�����
�����ĺ���ǽ����һ������(paizi)��
LONG);

    set("item_desc",([
        "paizi"  :  "Ѻ��ڼ���  dou hg <amount> <money>\n"+  
                    "Ѻ��β����  dou lw <amount> <money>\n",  
    ]));  
    set("objects",  ([  /*  sizeof()  ==  1  */
        __DIR__"npc/jixian"  :  1,
    ]));
    set("exits",  ([  /*  sizeof()  ==  1  */
        "south"  :  __DIR__"clubup",
    ]));
    set("light_up",  1);
    set("no_fight",  1);
    set("no_magic",  1);
    setup();
}

void  init  ()
{
    add_action  ("do_dou","dou");
    add_action  ("do_bian","bian");
    add_action  ("do_fight","fight");
    add_action  ("do_steal","steal");
    add_action  ("do_kill","kill");
    add_action  ("do_ji","ji");
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

int  do_dou  (string  arg)
{
    object  me  =  this_player();
    string  what;
    int  amount;
    string  money;
    object  ob;

    if  (!  arg  ||
            sscanf  (arg,"%s %d %s",what,amount,money)  !=  3)
        return  notify_fail("��ʹ�ã�  dou <Ѻ������> <��Ŀ> <����>\n");

    if  (what  !=  "hg"  &&
            what  !=  "lw")
        return  notify_fail("��ҪѺʲô���ļ���\n");

    ob  =  present  (money+"_money",  me);
    if  (!  ob)
        return  notify_fail("������û�����ֻ��ҡ�\n");
    if  (amount  <  1)
        return  notify_fail("���ѺһЩǮ��\n");
    if  (amount  >  ob->query_amount())
        return  notify_fail("�����ϵ�Ǯ����Ѻ��\n");
    if  (amount * (ob->query("base_value")) > 10000 )
        return  notify_fail("������İ������У��ٱ��������ˡ�\n");

    if  (me->query_temp  ("gamble_ji/amount")  >  0)
        return  notify_fail("���Ѿ�Ѻ���ˡ�\n");

    if  (room_status  >  1)
        return  notify_fail("�������ڶ����أ��Ե�Ƭ�̡�\n");

    me->set_temp("gamble_ji/kind",what);
    me->set_temp("gamble_ji/amount",amount);
    me->set_temp("gamble_ji/money",money);
    message_vision  (sprintf("$N�ó�%s%s%s������������һ�ţ�Ѻ��%s�ϡ�\n",
                                                    chinese_number(amount),
                                                    ob->query("base_unit"),
                                                    ob->query("name"),
                                                    jis[what]),
                                    me);
    if  (amount  ==  ob->query_amount())
        destruct  (ob);
    else
        ob->add_amount(-amount);

    return  1;
}

int  valid_leave(object  me,  string  dir)
{
    if  (dir  ==  "south")
    {
        if  (me->query_temp  ("gamble_ji/amount")  >  0)  
            message_vision  ("$N����Ѻ����Ǯ��Ҫ�ˡ�\n",me);
        me->delete_temp("gamble_ji");
    }
    return  ::valid_leave(me,dir);
}

void  gamble_prepare  ()
{
    object  room  =  this_object();
    tell_room  (room,"���׼��ɴ����Ҽ�������ó�һֻ��ڼ���һֻ��β����\n");
    hg_ji  =  new(__DIR__+"npc/douji");
    hg_ji->set("name","��ڼ�");
    hg_ji->move(room);
    lw_ji  =  new(__DIR__+"npc/douji");
    lw_ji->set("name","��β��");
    lw_ji->move(room);
    tell_room  (room,"���׼���˵���ã�����ѺǮ�ˣ�һӮ����\n");
    room_status  =  1;
    call_out  ("gamble_start",20);
}
  
void  gamble_start  ()
{
    object  room  =  this_object();
    tell_room  (room,"���׼���˵����ͣѺ��������\n");
    tell_room  (room,"Ȼ����ֻ�������ó����������ذ��ϣ��Ѽ��Ž����ڡ�\n");
    room_status  =  2;
    hg_ji->kill_ob(lw_ji);
    lw_ji->kill_ob(hg_ji);
    call_out  ("gamble_perform",1);
}

object  present_ji  (object  room)
{
    object  *list  =  all_inventory(room);
    int  i;
    i  =  sizeof(list);
    while  (i--)
    {
        if  (userp(list[i]))
            continue;
        if  (list[i]->id("ji"))
            return  list[i];
    }
}

void  gamble_perform  ()
{
    object  room  =  this_object();
    object  ji;

        if(!hg_ji || !lw_ji)
    {
        remove_call_out  ("gamble_perform");
        call_out  ("gamble_perform",1);
        return;
    }

    if  (!  living(hg_ji))
        hg_ji->die();
    if  (!  living(lw_ji))
        lw_ji->die();

    ji  =  present_ji  (room);
    if  (ji  &&  ji->is_fighting())
    {
        remove_call_out  ("gamble_perform");
        call_out  ("gamble_perform",1);
        return;
    }

    if  (ji->query("kee")<15)
    {
        ji->unconcious();
        ji->die();
    }

    call_out  ("gamble_finish",1);
    
}

void  player_wins  (object  who,  int  total)
{
    object  money  =  new  ("/clone/money/"+who->query_temp("gamble_ji/money"));
    int  amount  =  who->query_temp("gamble_ji/amount");
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
    object  money  =  new  ("/clone/money/"+who->query_temp("gamble_ji/money"));
    total  =  who->query_temp("gamble_ji/amount");
    message_vision  (sprintf("���׼��ɽ�$N���������ϵ�%s%s%s���ߡ�\n",
                                                    chinese_number(total),
                                                    money->query("base_unit"),
                                                    money->query("name")),
                                    who);
    destruct  (money);
}

void  clean_ji  ()
{
    object  room  =  this_object();
    object  ji;
    ji  =  present_ji  (room);
    if  (ji)
    {
        tell_room  (room,"���׼��ɽ�"+ji->query("name")+"�ݵ����ڡ�\n");
        destruct  (ji);
    }
    ji  =  present_ji  (room);
    if  (ji)
    {
        tell_room  (room,"���׼��ɽ�"+ji->query("name")+"�ݵ����ڡ�\n");
        destruct  (ji);
    }
    ji  =  present("corpse",room);
    if  (ji)
    {
        tell_room  (room,"���׼�������"+ji->query("name")+"��ͷһ�ӡ�\n");
        destruct  (ji);
    }
    ji  =  present("corpse",room);
    if  (ji)
    {
        tell_room  (room,"���׼�������"+ji->query("name")+"��ͷһ�ӡ�\n");
        destruct  (ji);
    }
}

void  gamble_finish  ()
{
    string  win;
    int  total,  i;
    object  room  =  this_object();
    object  ji  =  present_ji  (room);
    object  *list  =  all_inventory(room);
    if  (!  ji)
    {
        total  =  0;
        win  =  "none  of  them";
    }
    else  if  (ji->query("name")=="��ڼ�")
    {
        total  =  2;
        win  =  "hg";
    }
    else  //if  (ji->query("name")=="��β��")
    {
        total  =  2;
        win  =  "lw";
    }
    if  (total  >  0)
        tell_room  (room,"���׼���˵����"+jis[win]+"��ʤ��\n");
    else
        tell_room  (room,"���׼���̾Ϣ����˫���㱾��\n");
    i  =  sizeof(list);
    while  (i--)
    {
        if  (!userp(list[i]))
            continue;
        if  (list[i]->query_temp("gamble_ji/kind")  ==  win)
            player_wins(list[i],total);
        else  if  (list[i]->query_temp("gamble_ji/kind"))
            player_loses(list[i],total);
        list[i]->delete_temp("gamble_ji");
    }
    tell_room  (room,"\n");
    call_out  ("clean_ji",8);
    call_out  ("gamble_prepare",10+random(3));
}

int  do_bian  (string  arg)
{
    object  who  =  this_player();
    object  room  =  this_object();
    object  ob;

    if  (!arg)
        return  0;

    ob  =  present(arg,room);
    if  (ob  ==  hg_ji  ||  ob  ==  lw_ji)
    {
        message_vision  ("$Nͷ��������һ�꣬���ɼ���\n",who);
        message_vision  ("���׼��ɶ�$N˵�����ǿ����ػ��ǿ��㣿\n",who);
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
    if  (ob  ==  hg_ji  ||  ob  ==  lw_ji)
    {
        message_vision  ("$N�������ս��\n",who);
        message_vision  ("���׼��ɶ�$N˵�����ǿ��������ػ����˶�����\n",who);
        return  1;
    }
    return  0;
}

int  do_steal  (string  arg)
{
    object  who  =  this_player();
//    object  room  =  this_object();

    message_vision  ("$N͵͵����������֡�\n",who);
    message_vision  ("���׼��ɶ�$N˵���������Ҫ͵���������ɣ�\n",who);
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
    if  (ob  ==  hg_ji  ||  ob  ==  lw_ji)
    {
        message_vision  ("$N��ݺݵ���ɱ����\n",who);
        message_vision  ("���׼��ɶ�$N˵������Լ��Ը��Ϲ���ȥ��\n",who);
        return  1;
    }
    return  0;
}

int  do_ji  (string  arg)
{
    object  who  =  this_player();
//    object  room  =  this_object();

    message_vision  ("$N��ͷ���Ե���Ҫ��ʲô��\n",who);
    message_vision  ("���׼��ɶ�$N˵�������ֲ������ڣ��Լ���ʲô����\n",who);
    return  1;
}

int  do_cast  (string  arg)
{
    object  who  =  this_player();
//    object  room  =  this_object();

    message_vision  ("$N��ͷ���Ե����˼������\n",who);
    message_vision  ("���׼��ɶ�$N˵�����м�������ʩ�����ͳ���ȥ��ɡ�\n",who);
    return  1;
}

int  do_exert  (string  arg)
{
    object  who  =  this_player();
//    object  room  =  this_object();

    message_vision  ("$N��ʩ�ڹ���\n",who);
    message_vision  ("���׼��ɶ�$N˵�����������������������������죿\n",who);
    return  1;
}

int  do_perform  (string  arg)
{
    object  who  =  this_player();
//    object  room  =  this_object();

    message_vision  ("$N��ʩ�⹦��\n",who);
    message_vision  ("���׼��ɶ�$N˵�����������������������������죿\n",who);
    return  1;
}
