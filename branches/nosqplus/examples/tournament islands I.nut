function GetInfo(info_type){
	switch(info_type){
		case "name":
			return "Tournament Islands I";
		case "description":
			return "Tournament style map emhasizing fair starting locations, for 4 players.";
		case "args":
			GGen_AddIntArg("width","Width","Width of the map.", 1024, 128, 20000, 1);
			GGen_AddIntArg("height","Height","Width of the map.", 1024, 128, 20000, 1);
			GGen_AddEnumArg("smoothness","Smoothness","Affects amount of detail on the map.", 2, "Very Rough;Rough;Smooth;Very Smooth");
			GGen_AddEnumArg("feature_size","Feature Size","Affects size of individual hills/mountains.", 2, "Tiny;Medium;Large;Huge");
			
			return 0;
	}
}

function Generate(){
	local width = GGen_GetArgValue("width");
	local height = GGen_GetArgValue("height");
	local smoothness = 1 << GGen_GetArgValue("smoothness");
	local feature_size = GGen_GetArgValue("feature_size");

	GGen_InitProgress(9);

	local quarter = GGen_Data_2D(width / 2, height / 2, 0);
	
	local profile = GGen_Data_1D(2, 0);
	
	profile.SetValue(0, 100); 
	profile.SetValue(1, -100); 
	
	GGen_IncreaseProgress();
	
	quarter.RadialGradientFromProfile(width / 4, height / 4, (width > height ? height : width) / 4, profile, true);

	GGen_IncreaseProgress();

	local noise = GGen_Data_2D(width / 2, height / 2, 0);
	noise.Noise(smoothness,  (width > height ? height : width) / 6, GGEN_STD_NOISE);
	
	GGen_IncreaseProgress();
	
	noise.ScaleValuesTo(-110, 110);
	
	quarter.AddMap(noise);
	
	GGen_IncreaseProgress();
	
	local base = GGen_Data_2D(width, height, 0);
	
	base.AddTo(quarter, 0, 0);
	
	GGen_IncreaseProgress();
	
	quarter.Flip(GGEN_VERTICAL);
	
	base.AddTo(quarter, 0, height / 2);
	
	GGen_IncreaseProgress();
	
	quarter.Flip(GGEN_HORIZONTAL);
	
	base.AddTo(quarter, width / 2, height / 2);
	
	GGen_IncreaseProgress();
	
	quarter.Flip(GGEN_VERTICAL);
	
	base.AddTo(quarter, width / 2, 0);
	
	GGen_IncreaseProgress();
	
	base.TransformValues(GGEN_NATURAL_PROFILE, true);
	
	return base;
}