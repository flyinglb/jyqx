#include <ansi.h>
#include <command.h>

inherit NPC;
void create()
{
set_name("�����",({ "zhao linger","winzip" }));
        set("gender", "Ů��" );
set("age", 21);
        set("combat_exp", 20000000);
        set("attitude", "friendly");
set("per",30);
        set("inquiry", ([
 "��������": "��ѡ�ren <����> <id>",
        ]) );
setup();
//      carry_object(__DIR__"obj/gold")->wield();
//      carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
add_action("do_ren","ren");
}
int do_ren(string arg)
{
string id,w_name;
object me;

me = this_player();
if( !arg )
return notify_fail("����������˵��������������Ƽ����ź��ڶ���˵��\n");
sscanf(arg ,"%s %s" ,w_name ,id);
if(!w_name||!id)
return notify_fail("ʲô?(ʹ��ren ���������� Ӣ�Ĵ���\n)");
w_name = replace_string(w_name, "$BLK$", BLK);
w_name = replace_string(w_name, "$RED$", RED);
w_name = replace_string(w_name, "$GRN$", GRN);
w_name = replace_string(w_name, "$YEL$", YEL);
w_name = replace_string(w_name, "$BLU$", BLU);
w_name = replace_string(w_name, "$MAG$", MAG);
w_name = replace_string(w_name, "$CYN$", CYN);
w_name = replace_string(w_name, "$WHT$", WHT);
w_name = replace_string(w_name, "$HIR$", HIR);
w_name = replace_string(w_name, "$HIG$", HIG);
w_name = replace_string(w_name, "$HIY$", HIY);
w_name = replace_string(w_name, "$HIB$", HIB);
w_name = replace_string(w_name, "$HIM$", HIM);
w_name = replace_string(w_name, "$HIC$", HIC);
w_name = replace_string(w_name, "$HIW$", HIW);
w_name = replace_string(w_name, "$BLINK$", BLINK);
w_name = replace_string(w_name, "$NOR$", NOR);
me->set("weapon/name",w_name +NOR);	//����������
me->set("weapon/id",id);		//�����Ĵ���
say("��Quit �� Login һ�Ρ�\n");
return 1;
}
