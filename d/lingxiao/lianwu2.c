//LUCAS 2000-6-18
// lianwu1.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����������ǵ����䳡��ֻ�����⽣Ӱ��Ŀ��Ͼ�ӣ�һȺ��
���������ô����죬�˴˴���ѽ��ѷ֡�����������ϵ���ͣ�
�˴˼��������������µ���Ҳֻ��Ŭ���������Է����⡣
LONG );
        set("exits", ([ /* sizeof() == 2 */
            "west"      : __DIR__"fudian2",
        ]));
        set("objects", ([ 
            "/d/shaolin/npc/mu-ren" : 4,
        ]));
        set("outdoors", "lingxiao" );
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

