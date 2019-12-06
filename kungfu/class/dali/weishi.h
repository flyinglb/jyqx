// weishi.h ��������ʿ, ��ʦ
int ask_me()
{
	string sta;
	object ob = this_player();

	if( !stringp(sta =ob->query("dali_family_status")) ) {
	        command("say ����Ͷ��(toushen)�Ҵ������Ҷ����Ů�ɡ�");
	        return 1;
	}
	if( sta != "�ҳ�") {
		command("say ֻ�мҳ���������ʿ��\n");
		return 1;
	}
	if ((int)ob->query_skill("kurong-changong",1) < 60)
	{
		command("say ���뵱��ʿ���������깦�ɡ�\n");
		return 1;
	}
        ob->set_temp("fight_ok",1);
	command("say �ã���Ȼ������д裬�ǾͿ���ı�������ˡ�\n");
	return 1;
}

int accept_fight(object ob)
{
        object me  = this_object();
        if ( !ob->query_temp("fight_ok") ) return 0;

        remove_call_out("checking");
        call_out("checking", 1, me, ob);
        ob->delete_temp("fight_ok");
        return 1;
}

int checking(object me, object ob)
{
	int my_max_qi, his_max_qi;

	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");

	if (me->is_fighting()) 
	{
		call_out("checking",2, me, ob);
		return 1;
	}

	if ( !present(ob, environment()) ) return 1; 

	if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
	{
		command("say ������ʤ����������Ǵ���μҵĺõ��� ! ��ϲ���� !\n");
		command("say ����Ѿ�����ʤ�δ�����ʿ !\n");
		ob->set("dali_family_status","��ʿ");
		return 1;
	}
	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
	{
		command("say ����" + RANK_D->query_respect(ob) + 
			"���ö����ϰ�������ڴ���μ��������г���ͷ�� !\n");
		return 1;
	}
	return 1;  
}

void attempt_apprentice(object ob)
{
        if( !stringp(ob->query("dali_family_status")) ) {
		command("shake "+this_player()->query("id"));
		command("say ������Ͷ�����Ϊ�����������㽭�����񣬲�����ͽ�ˡ�\n");
		return;
	}
	if ((int)ob->query("shen") < 0  )
	{
		command("say �Ҵ�������������������ֺڵ�����򽻵�������ذɣ�");
		return;
	}
	if ((int)ob->query("combat_exp") > 10000 || (int)ob->query("age") >17 )
	{
		command("say �����������˴�������Ҳ����̫�����˰ɣ�");
		return;
	}
	command("say �ܺã��ܺá������븮���㵱���ұ�������������Ҳ�Ͳ����Լ����ˡ�\n");

	if( (string)ob->query("gender") == "����")
		ob->set("dali_family_status","�Ҷ�");
	else
		ob->set("dali_family_status","�Ů");

	command("recruit " + ob->query("id"));
}
