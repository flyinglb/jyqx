//ROOM: /d/yanziwu/shuiyun.c

inherit ROOM;

void create()
{
        set("short", "ˮ����");
        set("long",@LONG
���ĵ�һ��СС��̨ͤ�����滷ˮ��ֻ��������һ�������밶����
�������������棬ˮ��΢�һȺȺ���������ɼ�������һ��ʫ�黭
�⡣
LONG );
        set("outdoors", "yanziwu");
        set("exits", ([
            "west" : __DIR__"jiashan",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
