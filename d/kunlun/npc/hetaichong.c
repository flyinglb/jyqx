inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
	{
	set_name("��̫��", ({ "he taichong","he"}));
	set("age", 47);
	set("combat_exp", 900000);
	set("title",HIG"������������"NOR);
	set("gender","����");
//	set("attitude","taoism");//?
	set("str", 25);
	set("dex", 30);
	set("con", 30);
	set("int", 28);

	set("max_jingli",1000);
	set("jingli",1000);
	set("jiali",200);
	set("max_neili",3000);
	set("neili",3000);
	set("eff_jing",800);
	set("jing",800);
	set("eff_qi",2500);
	set("qi",2500);

	set_skill("force", 200);
	set_skill("sword", 200);
	set_skill("dodge", 190);
	set_skill("parry", 190);
	set_skill("unarmed",150);
	set_skill("literate",120);
	set_skill("xuantian-force", 180);
	set_skill("zhengliangyi-sword", 180);
	set_skill("yaoming-dodge", 180);
	set_skill("sanyin-unarmed",150);

	map_skill("dodge", "yaoming-dodge");
	map_skill("force", "xuantian-force");
	map_skill("parry", "zhengliangyi-sword");
	map_skill("sword", "zhengliangyi-sword");
	map_skill("unarmed","sanyin-unarmed");   
	prepare_skill("unarmed","sanyin-unarmed"); 

	create_family("������",4, "������������");
	set("chat_chance", 15);
	set("chat_msg", ({
	"��̫��˵�����뵱�괴����ʦ������ʥ����������޵��֣�����������һ�ɣ����񡭡�������  \n",
	"��̫��̾����˭���ҵ���ҽ�κ���õĲ���������Ϊ���ŵ��ӡ� \n",
	"��̫���ݺݵ�˵����Щû�õĵ��ӣ�������������Щӹҽ���� \n",
	}) );

setup();
	carry_object("/clone/cloth/male6-cloth")->wear();
	carry_object(__DIR__"obj/shansword")->wield();

}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("gender") != "����" )
	{        
		command("say �㻹��ȥ���ҷ��˰�ʦ�ɡ�");
		return;
	}
	if (ob->query_skill("xuantian-force",1) <= 50)
	{
	command("say ����ڹ���Ϊ������");
	return;
	}
	message_vision("��̫������$N��ͷ��΢΢���˵�ͷ��\n",ob);
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "swordsman")
	ob->set("class", "swordsman");
	ob->set("title", HIG "�����ɵ��������" NOR);

	return;
}


