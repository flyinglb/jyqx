// shiye.c ֪��ʦү

inherit NPC;

string ask_me();

void create()
{
	set_name("̷�Ѽ�", ({ "tan youji", "tan" }));
	set("title", "֪��ʦү");
	set("gender", "����");
	set("age", 57);

	set("combat_exp", 30000);
	set_skill("unarmed", 50);
	set_skill("dodge", 60);
	set_temp("apply/attack",  20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage",  20);
	set("shen_type", 0);

	set("inquiry", ([
		"�л���" : (: ask_me :)
	]) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
	
string ask_me()
{
	if ((int)this_player()->query_temp("marks/��"))
	{
		say("��С�ӣ�����ô֪����ϲ���Խл�����\n");
		command("lick");
		say("��Ȼ���ҳ���ʳ�ѣ��Ҿ͸�����ɡ�����������\n");
		command("whisper " + this_player()->query("id") + " ��ȥ������ȫ�۵µ��ϰ壬ֻҪ���������ҽ���ȥ�ģ����ͻ�...");
		this_player()->delete_temp("marks/��");
		this_player()->set_temp("marks/��2", 1);
		return "������....��....�Ǹ������ܺ�....\n";
	}
	else if((int)this_player()->query_temp("marks/��2"))
		return "���Ǹ��㽭�ˣ�Ҳû������ô���£�\n";
	else
		return "����˿��ż������\n";
}