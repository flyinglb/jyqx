//ROOM: /d/yanziwu/pindi.c

inherit ROOM;

void create()
{
        set("short", "Ʒ��ͥ");
        set("long",@LONG
ֻ��ǽ�Ϲ�������֮������������Ϸ���һ����ף�����Ľ������
���������������ˡ��������͵���̫�����ߣ�������Ľ�����ҽӴ���
�͵��������ˡ�
LONG );
        set("exits", ([
            "east"  : __DIR__"longfeng",
            "west"  : __DIR__"bozhou",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
