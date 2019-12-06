// room: /d/xingxiu/cave.c
// Jay 3/18/96

inherit ROOM;

int do_use(string arg);
int do_zuan(string arg);

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
���ɽ�������ֲ�����ָ��ֻ�г��ڴ�͸��һ˿���ߡ�
LONG );
        set("exits", ([
            "out" : __DIR__"tianroad5",
        ]));

        set("no_clean_up", 0);

        setup();
}

void init()
{
        add_action("do_use", "use");
        add_action("do_zuan", "zuan");
}

int do_use(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;
        if (!present("fire", me))  return 0;
        if( arg=="fire" ) {
             write(
             "���ȼ�˻��ۣ���������ʯ������һ���ѷ죬�ƺ�������(zuan)��ȥ��\n"
             );
             this_player()->set_temp("marks/��", 1);
             return 1;
       }
}

int do_zuan(string arg)
{
        object me;
        me = this_player();

        if (me->query_temp("marks/��") ) {
            message("vision", me->name() + "����һ�²�֪��ʲô�ط����ȥ�ˡ�\n",
                    environment(me), ({me}) );
            me->move("/d/xingxiu/cave2");
            message("vision", me->name() + "��ʯ�������˳�����\n",
                    environment(me), ({me}) );
            this_player()->set_temp("marks/��", 0);

            return 1;
        }
        else {
            write("�������Ķ���?!\n");
            return 1;
        }
}

