//ziweitang.c
inherit ROOM;

void create()
{
        set("short", "��΢��");
        set("long", @LONG
����������̵���΢�ã����ϵĴ����� "��΢����" ���ֲ�����
�������������Ŷ���˿����ɫ�����г���һ��������
LONG );
        set("exits", ([
            "east"      : __DIR__"tianweitang",
        ]));
        set("objects",([
             __DIR__"npc/yinwushou":1,
        ]));
        setup();
        replace_program(ROOM);
}
