//LUCAS 2000-6-18
inherit ROOM;

void create()
{
        set("short", "�ش���");
        set("long", @LONG 
�������������ҽ��������Ĵ���������Ļش��ӣ�һ����
����ŵ�һ�ɴ̱ǵ�ҩζ��ֻ�����а����˴��СС������ҩ,
��һ���뷢�԰׵������������ԣ�������һ�˰������Ա�ǽ��
����һ��������(tiaofu)�����Ǳ�������κ��˵Ĳ����͵ġ�
LONG );
        set("no_fight",1);
        set("item_desc", ([
                "tiaofu" : "��٢����,��ȸ������\n",
        ]));
        set("objects", ([
                __DIR__"npc/daifu" : 1,
        ]));
        set("exits", ([
                "west" : __DIR__"iceroad2",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

