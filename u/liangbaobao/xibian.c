// Room: /liangbaobao/xibian.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
        set("short", "Ϫ��");
        set("long", @LONG
һ��ɽϿ��ˮ�����������ֻ��ɽ���һ��������Ƶ��ٲ���к���£���
��һ��Ϫ������ʤ�������ļ��쳣��ˮ��Ю����֦ʯ�飬ת�۱����ò�֪ȥ�� 
�Ĺ�ˮ�����ɣ�εΪ��ۡ�
LONG );
        set("outdoors", "city");
        set("valid_xuantie-sword",1);
        set("no_clean_up", 0);
        set("exits", ([
                "east"  : __DIR__"jianzhong",
        ]));

        setup();
        replace_program(ROOM);
}
