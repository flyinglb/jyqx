inherit ROOM;
int do_use(string arg);
int do_tiao(string arg);
void create()
{
    set("short", "ʯ��");
    set("long", @LONG
���ɽ�������ֲ�����ָ���ڳ�������ôҲ�Ʋ�����
LONG
        );
	set("item_desc",([]));
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
"    �����ֻ������ʯ�ڶ��Ǿ�Ө���񣬵��·��ż������Σ�����������һ����
���Ӿ�Ȼ���Ǽ�����̣�ԭ��ɽ���ܱգ����ܷ��֣����Զ������²������á�\n"

             );
    set("long", @LONG
�����ֻ������ʯ�ڶ��Ǿ�Ө���񣬵��·��ż������Σ�����������һ����
���Ӿ�Ȼ���Ǽ�����̣�ԭ��ɽ���ܱգ����ܷ��֣����Զ������²������á�
LONG
);
    set("item_desc", ([
        "ʯ��" : 
"    ʯ������һ���ѷ죬�Ӻ�������ѷ���Ʈ����������硣\n", 
])); 
             this_player()->set_temp("marks/��2", 1);
             return 1;
       }
	return 0;
}
int do_tiao(string arg)
{
        object me;
        me = this_player();
        if (me->query_temp("marks/��2") ) {
        if( !arg || arg!="down") return notify_fail("��Ҫ��������\n");          
            write("����ԥ��һ�£�����������������ȥ��\n");
        if ((int)me->query_skill("dodge",1) < 300 ) {
        message("vision",me->name()+"��������׹ȥ���������׶༪����!\n",
            environment(me), ({me}) );
        me->unconcious();
        me->receive_wound("qi", 200);
        me->move(__DIR__"room33");
        message("vision","�飡��һ���˵���������\n", environment(me));
        return 1;
        }
            message("vision", me->name() + "��ಡ���һ��������ȥ��\n", environment(me), ({me}) );
            me->move(__DIR__"room33");
            message("vision", me->name() + "����������������\n",
                    environment(me), ({me}) );
            this_player()->delete_temp("marks/��2");
            return 1;
        }else {
            write("�������Ķ���?!\n");
            return 1;
        }
}
