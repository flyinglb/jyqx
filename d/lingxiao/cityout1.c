//LUCAS 2000-6-18
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����������ǵĳ��⣬����������ǰ���Ǹ��ʵĳ�ǽ������
������ӳ����ߣ���ҪԽǽ���룬�ǲ�̫���ܵġ���������Ұ��
�ܶ࣬���Բ���ʲô��ȫ�ĵط������ǸϿ���ǰɡ�
LONG
        );
        set("exits", ([
                "east" : __DIR__"shanya",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
