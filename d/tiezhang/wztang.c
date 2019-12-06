// Room: /u/zqb/tiezhang/wztang.c
#include <ansi.h>

inherit ROOM;
string look_bian();

void create()
{
	set("short", HIY"��ָ��"NOR);
	set("long", @LONG
    ����һ����ȫ�û��������ɵĴ�����͸��������˵ĺ�����������
��û�д������Ե���ɭ�ڰ������Ե�ǽ���ϲ������ͻ�ѣ�ɢ������ƵĹ�
�����ž��Ĵ����в�ʱ��������ž��ȼ���������������аڷ��Ű����ı�
�������Է�����ʮ�������ӣ�ֻ���������д���ʱ�������Ż��������벿��
���顣�������ǽ�Ϲ���һ���ƽ�ĺ���(bian)��������һ��С��ͨ�����
��
LONG	);
        set("item_desc", ([ 
        "bian"       :       (: look_bian :),
]));
	set("exits", ([ 
  "east" : __DIR__"zoulang-1",
  "southdown" : __DIR__"guangchang.c",
  "west" : __DIR__"zoulang-2.c",
  "north" : __DIR__"hxfang.c",
]));
    set("objects", ([ 
  __DIR__"npc/qqren" : 1,
  __DIR__"npc/xiaotong" : 1,
]));

	set("no_clean_up", 0);

	setup();
	
}
string look_bian()
{
    return
    "\n"
               HIY"          ####################################\n"
                  "          ####                            ####\n"
                  "          ####    ��    ָ    ��    ��    ####\n"  
                  "          ####                            ####\n"
                  "          ####################################\n"NOR;
    "\n";
}
