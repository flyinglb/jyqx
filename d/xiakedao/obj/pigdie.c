// pigdie.c

inherit ITEM;
void init()
{
        add_action("do_get","get");
        add_action("do_ge","ge");
        add_action("do_ge","cut");
}

void create()
{
        set_name("����", ({ "pig", "pigdie" }) );
        set("long", "����һֻ��ȥ��Ұ��ͷ��(zhutou)��ǰ��(forleg)������(backleg)��
���ü�Ϊ��׳��\n");
        set_temp("zhutou", 1);
        set_temp("forleg", 1);
        set_temp("backleg", 1);
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("value", 300);

        }
        setup();
}

int do_get(string arg)
{
        object me=this_player();
        object ob;
        ob=this_object();
        if( !arg )
            return notify_fail("��Ҫ��ʲô��\n");

        if( (string)arg=="pig")
        {
              if( me->query("str")<25 )
              {
                     message_vision("��ֻҰ��̫���ˣ����ò�����\n", me);
                     return 1;
              }
              message_vision("�㿸��һ��ֻ��̫���ˣ������ܲ��ˡ�\n", me);
              ob->move(me);
              return 0;
        }
}

int do_ge(string arg)
{
        object me=this_player();
        object ob;
        if(!arg||arg=="")
              return notify_fail("��Ҫ��ʲô������\n");
        if( (string)arg=="pig")
              return notify_fail("��Ҫ����һ���֣�\n");
        if( (!objectp(present("cut knife", me)) ))
        {
              message_vision("��û�к��ʵĶ������С��аѲ˵����֮��ľͺ��ˡ�\n", me);
              return 1;
        }

        switch( (string)arg) {
        case "zhutou" :  if( query_temp("zhutou")==1)
                         {
                             message_vision("�㿳��Ұ���ͷ��\n", me);
                             ob=new(__DIR__"zhutou");
                             ob->move(me);
                             set_temp("zhutou" , 0);
                             break;
                         }
                         else
                         {
                             message_vision("��Ұ���ͷ�ѱ��˿����ˡ�\n", me);
                             return 1;
                         }
        case "forleg" :  if( query_temp("forleg")==1)
                         {
                             message_vision("�㿳��Ұ���ǰ�š�\n", me);
                             ob=new(__DIR__"forleg");
                             ob->move(me);
                             set_temp("forleg", 0);
                             break;
                         }
                         else
                         {
                             message_vision("��Ұ���ǰ���ѱ��˿����ˡ�\n", me);
                             return 1;
                         }
        case "backleg" : if( query_temp("backleg")==1)
                         {
                             message_vision("�㿳��Ұ��ĺ�š�\n",me);
                             ob=new(__DIR__"backleg");
                             ob->move(me);
                             set_temp("backleg", 0);
                             break;
                         }
                         else
                         {
                             message_vision("��Ұ��ĺ����ѱ��˿����ˡ�\n", me);
                             return 1;
                         }

        }
        if ((query_temp("zhutou")==0) && (query_temp("forleg")==0) && (query_temp("backleg")==0))
        {
            this_object()->move(environment(me));
            destruct(this_object());
        }
        return 1;
}

