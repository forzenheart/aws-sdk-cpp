﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/connectcases/model/UpdateCaseRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::ConnectCases::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

UpdateCaseRequest::UpdateCaseRequest() : 
    m_caseIdHasBeenSet(false),
    m_domainIdHasBeenSet(false),
    m_fieldsHasBeenSet(false)
{
}

Aws::String UpdateCaseRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_fieldsHasBeenSet)
  {
   Array<JsonValue> fieldsJsonList(m_fields.size());
   for(unsigned fieldsIndex = 0; fieldsIndex < fieldsJsonList.GetLength(); ++fieldsIndex)
   {
     fieldsJsonList[fieldsIndex].AsObject(m_fields[fieldsIndex].Jsonize());
   }
   payload.WithArray("fields", std::move(fieldsJsonList));

  }

  return payload.View().WriteReadable();
}




