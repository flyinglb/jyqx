// nroad4.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","��ѩɽɽ·");
        set("long",@LONG
��ѩɽ��´�ĵ��Ʋ������ߣ���Χ����һЩСɽ��������һ��
��Ժ��ɽ�������Ե��쳣�ߴ���Ժ��ƽ�����ͣ����ɴ�ʯ���ɣ�ǽ
���ʵ������խС��
LONG );
        set("exits",([
                "north"   : __DIR__"nroad3",
                "westup"  : "/d/xueshan/shanmen",
        ]));
//        set("objects",([
//        ]));
        set("outdoors", "xueshan");
        setup();
        replace_program(ROOM);
}

