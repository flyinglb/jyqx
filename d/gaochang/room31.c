inherit ROOM;
int do_use(string arg);
int do_tiao(string arg);
void create()
{
        set("short", "��");
        set("long", @LONG
���ɽ�������ֲ�����ָ���ڳ�������ôҲ�Ʋ�����
LONG
        );
        setup();
}
void init()
{
        add_action("do_use", "use");
        add_action("do_tiao", "tiao");
}
int do_use(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if (!present("fire", me))  return 0;
        if( arg=="fire" ) {
             write(
"    ȡ������һ�Σ�����һ����ԭ����ȥ������ʮ�߰��ɸߣ����ڵ���Զ
�������Ϊ�͡�\n"
             );
        set("long", @LONG
ƾ����۵�΢�⣬����Կ���������ȥ������ʮ�߰��ɸߣ����ڵ���Զ
�������Ϊ�͡�
LONG
        );
             this_player()->set_temp("marks/��1", 1);
             return 1;
       }
}
int do_tiao(string arg)
{
        object me,ob;
        me = this_player();
        if (me->query_temp("marks/��1") ) {
        if( !arg || arg!="down") return notify_fail("��Ҫ��������\n");          
        write("����ԥ��һ�£�����������������ȥ��\n");
    if ((int)me->query_skill("dodge",1) < 300 ) {
        message("vision",me->name()+"��������׹ȥ���������׶༪����!\n",
            environment(me), ({me}) );
        me->unconcious();
       me->receive_wound("qi", 200);
        me->move(__DIR__"room32");
        message("vision","�飡��һ���˵���������\n", environment(me));
        return 1;
        }
            message("vision", me->name() + "��ಡ���һ��������ȥ��\n",
                    environment(me), ({me}) );
            me->move(__DIR__"room32");
            message("vision", me->name() + "����������������\n",
                    environment(me), ({me}) );
            this_player()->delete_temp("marks/��1");
           if ( objectp(ob=present("fire", this_player())) )     {
            message_vision("$N��һ��, �����Ӳ�֪�������ˡ�\n", me);
            destruct(ob);
            return 1;
           }
        } else {
            write("�������Ķ���?!\n");
            return 1;
        }
}
