// mtroad.c  ɽ·

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����һ��ɽ·��������ïʢ��ɭ�֣���һ��Ů�����������ϱ�
�������ϱ߾���Ħ�����ˣ�һ����ɭ�ֲ���������֮�������㲻��
�����Լ������ǿ��߰ɡ�
LONG );
        set("outdoors", "xiakedao");
        set("exits", ([
            "south" : __DIR__"mtyadi",
            "east"  : __DIR__"mtroad1",
        ]));
        set("objects",([
            __DIR__"npc/dingdang" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
