inherit ROOM;			   
      
void create()
{
        set("short", "������");
        set("long",@LONG
�����Ǻ�ľ�µĵڶ����ð׻��õ������ҡ�������ש�̵ء�
������һ����(box1).
LONG );		  
        set("exits", ([	
	    "west"      : __DIR__"qing",
	]));
	set("item_desc", ([
            "box1": "���Ǹ������Ƶĺ��ӣ������Ա��˴򿪣��տ���Ҳ ��\n",
       	]) );
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
