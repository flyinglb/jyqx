//  Room:  /d/city/road1.c

inherit  ROOM;

void  create  ()
{
	set("short",  "�����");
	set("long",  @LONG
����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�����ͨ��֬
��֮�������ݣ�������ֱ�ﳤ���ǡ�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"  :  "/d/city/ximenroad",
		"west"  :  __DIR__"hanguguan",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		"/d/mingjiao/yuan/zhaomin" : 1,
		"/d/mingjiao/yuan/zhao1" : 1,
		"/d/mingjiao/yuan/qian2" : 1,
		"/d/mingjiao/yuan/sun3" : 1,
		"/d/mingjiao/yuan/li4" : 1,
/*
		"/d/mingjiao/yuan/zhou5" : 1,
		"/d/mingjiao/yuan/wu6" : 1,
		"/d/mingjiao/yuan/zheng7" : 1,
		"/d/mingjiao/yuan/wang8" : 1,
*/
	]));
	set("outdoors",  1);
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}






