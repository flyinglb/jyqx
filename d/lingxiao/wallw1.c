//LUCAS 2000-6-18
// wallw1.c

inherit ROOM;

void create()
{
        set("short", "��ͷ");
        set("long", @LONG
��紵ѩ������ǧ����м���º���գ����������ƿա���ƽ
�ز���ѩ����ɳ����ơ������������������ʵд�ա�Զ����ϡ
�ɼ�һ�����ڵ��ر���Ϊ�����ӡ��ĺ������ڿ�硢��ѩ������
��ӳ���£�����������֮�ˡ�
LONG );
        set("outdoors", "lingxiao");
        set("no_clean_up", 0);

        set("exits", ([
                "west" : __DIR__"wallw2",
                "eastdown"  : __DIR__"gate",
        ]));
        set("objects", ([
                __DIR__"npc/dizi" : 1,
        ])); 
        setup();
        replace_program(ROOM);
}

