// Room: /d/xingxiu/jiayuguan.c
// Jay 3/17/96

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
���ǳ��������Ĺذ������²�ɣ�����ڲ�ס���ķ�ɡ�Ⱥɽ����֮�£�������
���ۻ롣�������򰲶�������ս�£��߹��ؾ��Ѵ�Ϊ���١�һ�����������ͨ��
��ԭ���������������������ġ�˿��֮·����
LONG );
        set("outdoors", "xingxiuhai");
        set("exits", ([
                "eastup" : __DIR__"xxroad3.c",
                "west" : __DIR__"silk1.c",
        ]));
        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

