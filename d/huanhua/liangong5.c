// liangong5.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�߽����ڣ�ֻ������ûʲô���裬�����տ����䣬���м�����®���ˡ��е���
�����������е�����ϰȭ�š�Ϊ�˷�����������ׯ��ר��Ϊ��Ҳ����˼��Ŵ�
���Աߣ���������ܴ�Ҳ������ʲô������Կ�ʼ�����ˡ�
LONG
	);
        set("exits", ([ 
		"east" : __DIR__"huayuan2",
		
]));
        set("no_fight",0);
        set("no_steal",0);
        set("sleep_room",1);
	setup();
	replace_program(ROOM);
}
