// Room: /d/xiangyang/qianzhuang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "Ǯׯ");
	set("long", @LONG
������������Ǯׯ����Ϊ������ҵ�൱������ص��̺�
������������Ǯ������Ǯׯ���кܶ����ڴ�ȡǮ��Ҳ�����ڶ�
��������������ô���Ǯ�ƹ�����ȥ�����������۲���������
�´�е�ǰ��ȫ��һ�µ���Ԫ����Ǯׯ��ҵ���ɻ�ɽ���ӽӹܣ�
֧Ԯ���������͹����ˡ�ǽ������һ������(paizi)��
LONG );
	set("item_desc", ([
		"paizi" : @TEXT
     ��Ǯׯ�ṩ���·���
      ��Ǯ        deposit����cun
      ȡǮ        withdraw����qu
      Ǯ�Ҷһ�    convert����duihuan
      ����        check����chazhang
TEXT
	]));
	set("no_fight", 1);
	set("exits", ([
		"east" : __DIR__"southjie1",
	]));
	set("objects", ([
		__DIR__"npc/huangzhen" : 1,
	]));
	setup();
	replace_program(ROOM);
}

