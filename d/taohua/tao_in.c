#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "�һ�����");
        set("long",@LONG
����һƬ�һ��ĺ�������һ���޼ʣ�ȫ��ʢ�����һ���΢�������
��Ӣ�ͷס���Χ�����ĵġ�Զ��ż������һ����С�������һƬ��
���֣���������һ��Сͤ�ӡ�
LONG );
       set("exits", ([
           "south" : __DIR__"tao0",
           "north" : __DIR__"haitan",
       ]));
       set("objects", ([
           CLASS_D("taohua")+"/feng" : 1,
       ]) );
    
       set("outdoors","taohua");
//       set("no_clean_up", 0);
       setup();
       replace_program(ROOM);
}
void init()
{
        object ob;
        mapping myfam;
	ob = this_player() ;
        if(query("exits/south")) 
        if ((int)ob->query_skill("qimen-wuxing",1) >= 100 )
        {
        delete("exits/south");
        set("exits/south", __DIR__"tao_out");
	return ;
        }
        myfam = (mapping)ob->query("family");
        if(myfam && myfam["family_name"] == "�һ���")
        {
        delete("exits/south");
        set("exits/south", __DIR__"tao_out");
	return ;
        }         
	delete("exits/south");
        set("exits/south", __DIR__"tao0");
}
