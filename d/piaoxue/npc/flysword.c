#include <ansi.h>
inherit NPC;
int  piaoxue();

void create()
{
        set_name("���ɷɽ�", ({ "fly sword","sword" }));
	set("title", HIM"��Ʈ"HIW"ѩ"HIM"ɽׯ��"BLINK+HIR"�������ʹ��"NOR );
        set("gender", "����");
        set("age", 20);
        set("long","����Ʈѩɽׯ�Ľ���ʹ�ߣ����������·Ӣ��ȡ��Ʈѩɽׯ\n",);
        set("no_get",1);

        set("combat_exp", 1000000);
        set("shen_type", 1);

	set("eff_qi",2000);
	set("qi",2000);
        set("max_neili", 1000);
        set("neili", 1000);
        set("jiali", 100);

        set_skill("force", 200);
        set_skill("unarmed", 400);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set("inquiry", ([
                
                "Ʈѩɽׯ" :   (: piaoxue :)

        ]) );

        setup();
	carry_object("/clone/misc/cloth")->wear();
 }

int piaoxue()
{
        object where;
	object me;
	object room;
	me = this_player();
	where = environment(me);
	if ((string)where->query("short")=="���")
	        {
        	message_vision("$N����Ц�ݶ�$n˵������ȥƮѩɽׯ���ã�û���⡣\n",this_object(),me);
	        room = load_object("/d/piaoxue/dating");
        	message_vision("ֻ�����ɷɽ����һָ��һ�������Χ��$N����һ��������˲����ˣ�\n",me);
        	me->move(room);
                }
        else    {
                message_vision("$N����ضԶ�$n˵����ֻ�е����߲�������ȥƮѩɽׯ��\n",this_object(),me);
                return 1;
                }
        
}
