// Room: /d/xingxiu/xxroad5.c

inherit ROOM;

void create()
{
        set("short", "�����ɴ�����");
        set("long", @LONG
����ԭ����һ������ɽ���ϵ���Ȼ�ܶ�����Ϊ�ص����ܶ��Ҷ��п���ʮ��
��������ɰ�����������һ���ֿ⡣
LONG );
        set("exits", ([
            "out" : __DIR__"xxroad5",
        ]));
        set("objects", ([
                __DIR__"obj/yanwu" : 1,
                __DIR__"obj/hulu" : 2,
                __DIR__"obj/menghan_yao" : 1,
                __DIR__"obj/xxqingxin-san" : 1,
                "/clone/book/dujing_1"  : 1
        ]));
//        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}
