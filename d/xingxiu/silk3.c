// /d/xingxiu/silk3.c
// Jay 3/17/96

inherit ROOM;

int do_climb(string arg);

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
����һ����ԭ������֮����̵����������������ɽ���������������
������һ���������������ԭ��������ͨ������������һ����ɳ�ѻ��γ�
��ɽ(mount)��
LONG );
        set("outdoors", "xingxiuhai");
        set("exits", ([
                "southeast" : __DIR__"silk2",
		"west" : __DIR__"silk4",
        ]));
        set("objects", ([
                "/d/hangzhou/honghua/huo" :1,
        ]));
        set("item_desc", ([
                "mount" : 
        "����һ����ɳ�ѻ��γɵ�ɽ��΢�紵����ɳɽ�������˵���������\n" 
	"��������Ȼ�����﷢�����Ե���̾��"
        ]) );
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;
        if( arg=="mount") {
                message("vision",
		me->name() + "�ԳԿԳ���ɳɽ����ȥ��\n",
                environment(me), ({me}) );
                me->move("/d/xingxiu/shashan");
                message("vision",
                me->name() + "��ɳɽ������������ճ��һ��ɳ�ӡ�\n",
                environment(me), me );
                return 1;
        }
}

