//LUCAS 2000-6-18
// walle2.c

inherit ROOM;

void create()
{
        set("short", "��ͷ");
        set("long", @LONG
Զɽ���죬����������Է����£�ֻ����ɫ��ѩ����������
֮����Ω����ѩ���࣬����߮�ˡ���Į�Բԣ�Զ��һӥ���裬��
��ֱ�ɾ�����������ֱ����£�������죬˲�����٣�ֻ�а���
ǧ�أ����������³�������Ʈ����
LONG );
        set("outdoors", "lingxiao");
        set("no_clean_up", 0);

        set("exits", ([
                "west" : __DIR__"walle2",
        ]));
        set("objects", ([
                __DIR__"npc/dizi" : 1,
        ])); 
        setup();
        replace_program(ROOM);
}

