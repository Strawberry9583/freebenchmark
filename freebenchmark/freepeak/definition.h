#pragma once
#ifndef DEFINITION_H
#define DEFINITION_H

enum compare { MIN_OPT = 0, MAX_OPT };
enum division_model { DM_Random = 0, DM_UserDefined };
enum property_type{ EUCLIDEAN_DISTANCE };

enum parameter {
	param_numDim, param_numPeak, param_proName, param_algName, param_maxEvals, param_shiftLength, param_changeType, param_proId, \
	param_runId, param_algId, param_changeRatio, param_flagNumPeakChange, param_flagNumDimChange, param_peakNumChangeMode, param_flagNoise, \
	param_flagTimeLinkage, param_comDBGFunID, param_changeFre, param_noiseSeverity, param_timelinkageSeverity, param_popSize, param_evalCountFlag, \
	param_stepIndi, param_trainingTime, param_subPopSize, param_overlapDgre, param_convThreshold, param_timeWindow, param_sampleFre, param_gOptFlag, \
	param_workingDir, param_convFactor, param_numRun, param_numTask, param_exlRadius, param_solutionValidationMode, param_populationInitialMethod, \
	param_hibernatingRadius, param_minNumPopSize, param_numChange, param_numObj, param_case, param_resource4BestPop, param_dataFile1, \
	param_xoverProbability, param_mutProbability, param_proTag, param_numGOpt, param_noiseFlag, param_predicFlag, param_changeType2, \
	param_peaksPerBox, param_interTest1, param_interTest2, param_interTest3, param_interTest4, param_numBox, param_heightConfigMode, param_peakCenter, \
	param_numParetoRegion, param_validRadius, param_attraction, param_radius, param_jumpHeight, param_variableRelation, param_peakShape, param_divisionMode, \
	param_peakOffset, param_flagIrregular, param_flagAsymmetry, param_flagRotation, param_dataFile2, param_dataFile3, param_dataDirectory1, \
	param_maxIter, param_maxSucIter, param_epsilon, param_mutationSchemeDE, param_updateSchemeProbabilityLearning
};

#endif // !DEFINITION_H
