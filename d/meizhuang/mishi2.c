// mishi2.c
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "��԰");
        set("long", @LONG
����һ��СС��԰�ӣ����������˴��СС����������֦�еĳ��ɼ�
�أ��еĻ�����֦��Ҷ�����м���һ���ľ(guanmu)�͵Ͱ����ģ�������
��ǳ�����עĿ���㲻��������࿴�����ۡ�
LONG
        );
        set("exits", ([
            "west" : __DIR__"xiaoyuan",
        ]));
        set("objects", ([
            __DIR__"obj/guanmu" : 1,
        ]) );
        set("outdoors", "meizhuang");
        setup();
}
void reset()
{
        object *inv;
        object con, item, guanmu;
        ::reset();
        guanmu= present("guanmu", this_object());
        inv = all_inventory(guanmu);
        if( !sizeof(inv)) {
        con = new(__DIR__"obj/honghua");
        item = new(__DIR__"obj/zhuguo");
        item->move(con);
        con->move(guanmu);
        }
}

