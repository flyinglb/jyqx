// sroad4.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","��ѩɽ��");
        set("long",@LONG
�����Ѿ����˲رߣ���ѩɽ��ɽ�ڡ���ѩɽ�ֽ��ɽ��λ�ڴ�
��֮�䣬����ɽ�Ƹ߾���ɽ�������겻���Ļ�ѩ���ʶ�����������
�����˼���ֻ�м�ֻͺӥ�ڸߴ�������������ããѩɽ��
LONG );
        set("exits",([
                "eastdown"  : __DIR__"sroad3",
                "westup"    : __DIR__"sroad5",
        ]));
        set("objects",([
                __DIR__"npc/eagle": 2,
        ]));
        set("outdoors", "xueshan");
        set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}
