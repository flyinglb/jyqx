// Room: /d/taishan/xiayi.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ƿ���̨��ߵ�������������������ʹ��ƽʱ����ɽʱ��
ͨ������������������ֹ������������з��Ű�̫ʦ�Σ�����ʹ��
���������濪���������Ҹ������ż�λ������ʿ������ȥ������
�ݣ�����һ��ׯ������
LONG );
	set("exits", ([
		"west" : __DIR__"fengchan",
	]));
	set("objects",([
                 "/clone/npc/shang-shan" : 1,
		__DIR__"npc/wei-shi2" : 3,
	]));
//        set("no_clean_up", 1);
	setup();
	replace_program(ROOM);
}
