// Room: /d/taishan/zhengqi.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ƿ���̨�ұߵ��������������˷���ʹ��ƽʱ����ɽʱ��
ͨ�����������ﴦ�����ֹ������������з��Űѻ�Ƥ�Σ�����ʹ��
���������濪���������Ҹ������ż�λ������ʿ������ȥɱ����
�ڣ�������Ȼ�������⡣
LONG );
	set("exits", ([
		"east" : __DIR__"fengchan",
	]));
	set("objects",([
		"/clone/npc/fa-e" : 1,
		__DIR__"npc/wei-shi2" : 3,
	]));
//        set("no_clean_up", 1);
	setup();
	replace_program(ROOM);
}

