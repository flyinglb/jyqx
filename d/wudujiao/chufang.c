// by mayue


inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������嶾�̵ĳ�����ƽ�������Ƕ��˿��Ե�����Ҫ(yao)Щʳ�
�������������һ�����ʦ��æ����ͷ�󺹡��ݽǷ���һ����ˮ�ס�  
LONG
	);
//        set("outdoors", "wudujiao");

	set("exits", ([
//		"east" : __DIR__"bingqi",
		"south" : __DIR__"beiyuan",
//		"west" : __DIR__"damen",
//		"north" : __DIR__"chufang",
	]));
        set("objects", ([
                 __DIR__"obj/ganchai": 3,
                 __DIR__"obj/hulu": 1,
                 __DIR__"npc/tian": 1,
	]));
       set("resource", ([ /* sizeof() == 1 */
              "water" : 1,
       ]));   
	setup();
//	replace_program(ROOM);
}
int valid_leave(object who, string dir)
{
    object where=environment(who);
       if(present("baozi", who))
        {
              return notify_fail("������������\n");
              who->move(where);
              return 1;
        }
       if(present("hulu", who))
        {
	       return notify_fail("�㲻�ܰѺ�«���ߣ�\n");
              who->move(where);
              return 1;    
         }
        else return ::valid_leave();
}
