// ben.h for fight

void init()
{
	::init();

	if (interactive(this_player()) && this_player()->query_temp("fighting"))
	{
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
		this_player()->add_temp("beat_count", 1);
	}
}
void attempt_apprentice(object ob)
{
        if ((int)ob->query_skill("kurong-changong", 1) < 150) {
                command("say ���ڹ���Ϊ��������򣬽�������Ҳ��ͽ�͡�\n");
                return;
        }
	command("say �ðɣ����ľ�����������׼ҵ����ˡ�");
	command("recruit " + ob->query("id"));
}

