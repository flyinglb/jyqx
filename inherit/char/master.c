#include <dbase.h>
#include <login.h>

int prevent_learn(object me, string skill)
{
	int betrayer;

	if( betrayer = me->query("betrayer") )
	{
		if( me->query_skill(skill, 1) >= this_object()->query_skill(skill, 1) - betrayer * 20 ) {
			message_vision("$N��ɫ���ƺ���$n����ʮ�����Σ�Ҳ��������$p��ǰ����ʦ�ŵ����� ...��\n",
				this_object(), me );
			command("say �� .... ʦ���ܽ���Ķ����ˣ����������Լ����ɡ�");
			return 1;
		}
	}

	if( !me->is_apprentice_of(this_object())
	&&	(int)this_object()->query_skill(skill, 1) <= (int)me->query_skill(skill, 1) * 3 ) {
		command("hmm");
		command("pat " + me->query("id"));
		command("say ��Ȼ���������µĵ��ӣ����ǲ����ҵĵմ����� ....");
		command("say ��ֻ�ܽ�����Щ��ǳ�ı��Ź��������Ļ���ȥ����ʦ��ѧ�ɡ�");
		return 1;
	}

	return 0;
}
