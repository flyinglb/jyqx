// Room: /city/dangpu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ����������ƽ���Ƶĵ��̣�һ����߸ߵĹ�̨���������
ǰ����̨�ϰ���һ������(paizi)����̨���������ϰ壬һ˫������
�������´������㡣
   ͨ�棺����ԭ���ĵ���ϵͳ��һ�����⣡ϣ������ǽ�ԭ�����е�
����ȡ��������С��ի�����������   лл��λ������
    ¥���¿���С��ի��
LONG
	);
	set("no_fight", 1);
	set("no_beg",1);
        set("no_sleep_room",1);
	set("no_clean_up", 0);
	set("item_desc", ([
		"paizi" : "��ƽ����\n
sell        �� 
buy         ��
redeem      ����
value       ����
",
	]));
	set("objects", ([
		__DIR__"npc/tang" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"nandajie1",
		"up"   : __DIR__"xiaobaozhai",
	]));

	setup();
	replace_program(ROOM);
}

