//  Room:  /d/city/road3.c

inherit  ROOM;

void  create  ()
{
	set("short",  "��ٵ�");
	set("long",  @LONG
����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�����ͨ��
�ȹأ���������ֱ�ﳤ���ǡ�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"northwest" :  __DIR__"road4",
		"east"      :  __DIR__"zhongnan",
		"west"      :  "/d/quanzhen/guandao1",
	]));
	set("outdoors",  1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}






