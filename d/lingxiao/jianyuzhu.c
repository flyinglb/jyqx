//LUCAS 2000-6-18
// jianyuzhu.c

inherit ROOM;

void create()
{
        set("short", "�η�");
        set("long", @LONG
�������һƬ����ϸϸ���������ñ�����ʯ�ŵķ�϶���Լ�
ͷ��ȥ��ʯ�ž�����ҡ�Σ���֪�ж���ʵ��һ����ɫ�԰׵�����
�ˣ���ͷɥ�������ڵ��ϡ�
LONG );
        set("outdoors", "lingxiao");
        set("no_clean_up", 0);

        set("exits", ([
                "west" : __DIR__"laolang",
        ]));
        set("objects", ([ 
                __DIR__"npc/zhu" : 1,
        ])); 
        setup(); 
        replace_program(ROOM);
}

