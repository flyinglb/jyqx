//LUCAS 2000-6-18
// jianyusun.c

inherit ROOM;

void create()
{
        set("short", "�η�");
        set("long", @LONG
����һ��СС���η�����һ�����������ʯ�ҡ����¸ߵͲ�
ƽ�����Ǿ�ʯ���������۾����²쿴��ֻ�������������΢��͸
�룬��Ŀ��ȥ���Ǹ�����һ�߼����Ķ�Ѩ��è����ɳ��룬ȴ��
С��Ҳ�겻��ȥ�����ͷ�ʱ�õ�С�ס�
LONG );
        set("outdoors", "lingxiao");
        set("no_clean_up", 0);

        set("exits", ([
                "east" : __DIR__"laolang",
        ]));
        set("objects", ([ 
                __DIR__"npc/sun" : 1,
        ])); 
        setup(); 
        replace_program(ROOM);
}

