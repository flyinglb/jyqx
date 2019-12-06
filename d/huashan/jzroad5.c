// Room: /d/huashan/jzroad5.c

inherit ROOM;
void create()
{
        set("short", "����ɽ����");
        set("long", @LONG
ɽ·Խ��ԽС����Χï��ɭ����ͽ��µ�é�ݷ�ס��·���ϲ���
��⣬�󲻼���·(road)�����ֱ�����ˡ�
LONG );
        set("exits", ([
                "northdown" : __DIR__"jzroad4",
        ]));
        set("item_desc", ([
                "road" : "·��ģģ�����������и���������̫����ʵ�ڿ�������\n",
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
"���ȼ�˻��ۣ�������һΧ����������ȥ��Ƥ���������顰����ɽ�����֡�
���һ���������ƺ�������(zuan)��ȥ��\n");
             this_player()->set_temp("marks/��1", 1);
             return 1;
       }
}

int do_zuan(string arg)
{
        object me;
        me = this_player();

        if (me->query_temp("marks/��1") ) {
             message("vision", me->name() + "��������һ��������������ˡ�\n",
                    environment(me), ({me}) );
             me->move(__DIR__"jzroad6");
             message("vision", me->name() + "���������˳�����\n",
                     environment(me), ({me}) );
             this_player()->delete_temp("marks/��1");
             return 1;
        }
        else {
             write("�������Ķ���?!\n");
             return 1;
        }
}
