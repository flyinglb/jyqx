// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "�׺�Ȫ");
	set("long", @LONG
�ഫ��ǰ������һ���׺�Ȫ������ˮ��������Ϊ̩ɽ֮�
��Ȫˮ����ӿ�����ϣ������ˮ���ɺ������ų��ϴ��һ��������
Ϊ������ϧ������һ����˽������С�٣�������Ȫˮ������������
�ŷ�ˮ֮˵����Ȫ�۶������׺�Ȫ�Ӵ˱�ɺ��ˡ�����ֻʣ��һ��
���š��׺�Ȫ�����ֵ�ʯ����Ϊ���������������ϣ�������ɽ
֮·��
LONG );
	set("exits", ([
		"northup"   : __DIR__"yitian",
		"southdown" : __DIR__"daizong",
	]));
	set("resource/water",1);
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

