//Created by RoomEditer on 99-5-9.
inherit ROOM;

void create()
{
	set("short","��ڣ��");
	set("long",@LONG
����ʱ��Ὺڣ��ʯ�飬¶�������ŵ�
�����������ڵ�һ���ڶ����ѽ�֮�䣬��һ
����ޱ��,����Լ�ĳߣ����������������
�����ڶ�����������������ĺ�����״��ȴ
�ǳ���֮�������߶೤��һ�ѽ�����������
�����߰�ʮ���֮ս��������صĽ𵶴�
�����������������ľ�������֡�ȴ��ƮƮ
�Ļ�����������վã����������Ѹ��ࡣ
LONG
	);
	set("exits",([
		"east" : "/u/liangbaoabo/jianzuo1",
	]));
	set("objects",([
		"/u/liangbaoabo/ziwei" : 1,
		"/u/liangbaoabo/tiesword" : 1,
		"/u/liangbaoabo/mujian" : 1,
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
