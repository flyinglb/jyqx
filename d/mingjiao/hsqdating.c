//HSQTING.C

inherit ROOM;

void create()
{
        set("short", "��ˮ�����");
        set("long", @LONG
�����Ǻ�ˮ��Ĵ����������ı���ī��������̨�ξ�Ϊ��ɫ��
ǹҷ��ӧ���������룬���õ���Įɭ�ϡ���������в輸����ˮ
������ʹ����������������ɱ����
LONG );
        set("exits", ([
                "south" : __DIR__"hsqchanglang",
        ]));
        set("objects", ([
                __DIR__"npc/tangyang": 1,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
